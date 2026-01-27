classdef ROTH < handle
%
% Class that encapsulates Relocatable Over The Hill stuff.
%-------------------------------------------------------------------------------------------------
  properties (Constant)
    someConstant = 1.0                         % This is some constant.
  end


  methods (Static)
  
    %---------------------------------------------------------------------------------------------
    function beamData_ = beamform(phaseWeights, elementData)
    % Use phase weights to beamform element data.
    %---------------------------------------------------------------------------------------------
      [nSamples, ~] = size(elementData);
      beamData_ = zeros(nSamples, 1);

      for ii = 1:nSamples
        beamData_(ii) = sum( elementData(ii,:) .* phaseWeights);
      end

    end

    %---------------------------------------------------------------------------------------------
    function fo = calculateDoppler(slantVelocity, fc)
    % Calculate doppler from slant velocity (m/s) and center frequency.
    % 
    % fo = fc * ( C ./ (C+v) ) - fc
    % 
    % Where:
    % fo is observed frequency
    % fc is center frequency of Linear Frequency Modulated signal
    % C  is the speed of light
    % v  is the velocity of source
    %---------------------------------------------------------------------------------------------
      % fo = ( fc * UNIVERSE.C./(UNIVERSE.C + slantVelocity) ) - fc;
      tmp = 2.0 .* slantVelocity ./ UNIVERSE.C;
      fo = tmp .* fc;
    end

    %---------------------------------------------------------------------------------------------
    function elementPhaseWeights = calculatePhaseWeights( ...
        pointingAngle, ...
        ROP_Fc, ...
        elementLat_, ...
        elementLon_, ...
        elementAlt_)
    % Calculate phase weights using:
    %   Pointing angle in degrees.
    %   Center frequency in Hertz.
    %   Element latitude, longitude, and altitude positions.
    %---------------------------------------------------------------------------------------------
      lambda = UNIVERSE.C/ROP_Fc;                                    % Calculate wave length.

      nElements = length(elementLat_);                               % nElements (last Element.)
      ii = 1;                                                        % First Element.
      jj = nElements;                                                % Last Element.

      [x0, y0, z0] = geodetic2ecef( wgs84Ellipsoid, ...              % Calculate antenna
        elementLat_(ii), elementLon_(ii), elementAlt_(ii) );         % element separation
      [x1, y1, z1] = geodetic2ecef( wgs84Ellipsoid, ...              % based on element 
        elementLat_(jj), elementLon_(jj), elementAlt_(jj) );         % latitudes and 
      separation = ...                                               % longitudes.
        sqrt( (x0-x1)^2 +  (y0-y1)^2 + (z0-z1)^2 )./nElements;       % 

      strt = nElements./2 - 0.5;
      stop = strt;
      elementNumber = -strt:1.0:stop;

      elementDisplacement = elementNumber .* separation;             % Calculate phase weights.
      term1 = 2.0 .* pi .* elementDisplacement ;                     %
      elementPhaseOffset = term1 .* sind(pointingAngle) ./ lambda;   %
      elementPhaseWeights = ...                                      %
        cos(elementPhaseOffset) - sin(elementPhaseOffset)*1i;        %
      %---------------------------------------------^---------------------------------------------
      %                                             |
      %                                      Complex Conjugate

    end

    %---------------------------------------------------------------------------------------------
    function dataFileName = createDataFileName( fileNameRoot, ROP )
    % Create a full path and file name URL for a data file in the "ZDATA00"
    % directory 
    %---------------------------------------------------------------------------------------------
      usrDir = getenv("USERPROFILE");
      gitDir = strcat(usrDir, '\GIT25');
      datDir = strcat(gitDir, '\ZDATA00');
      dataFileName = strcat(datDir, '\', fileNameRoot, '_', ROP.TText, '.mat');
    end

    %---------------------------------------------------------------------------------------------
    function [ROP, lfmSweep_, radarReturn_] = createRadarReturn(...
        t_, rangeBin_, doppler_, elevation_, ROP)
    % Create a RADAR return structure using:
    % 
    % t_         Time series.
    % rangeBin_  Calculated range bin values.
    % doppler_   Calculated doppler values.
    % elevation_ Calculated elevation for target observable logic.
    % ROP.Bw     RADAR Operating Parameter Bandwidth.
    % ROP.Swr    RADAR Operating Parameter Sweep rate.
    % ROP.Fs     RADAR Operating Parameter Sample rate.
    %
    % Return:
    % ROP        RADAR Operating Parameter.
    % lfmSweep   Linear Frequency Modulation Sweep structure
    % radarReturn_ Radar return.
    %---------------------------------------------------------------------------------------------
      lfmSweep = lfmSweepClass(ROP.Fs, ROP.Bw, ROP.Swr);             % Create one sweep of LFM.

      nSamps = length( lfmSweep.signal_ );                           %

      cw_Sweep = cwSignalClass(ROP.Fs, 0.0, nSamps);                 % Initialize CW object of 
                                                                     % same size.

      radarReturn_ = zeros(nSamps * (length(t_)-1), 1);              % Prepare output buffer.
      
      for ii = 1:(length(t_)-1)                                      % For each sweep of time 
                                                                     % step dt.
    
        RB = round(rangeBin_(ii));                                   % Make Range Bin integer.
    
        rangeAdjust = circshift(lfmSweep.signal_, RB);               % Simulate range with 
                                                                     % circular shift.
    
        cw_Sweep.genSignal(doppler_(ii), nSamps);                    % Simulate doppler with CW.
    
        strt = (ii - 1) * nSamps + 1;
        stop = ii * nSamps;
        
        radarReturn_(strt:stop) = ...                                % Create one sweep of return.
          rangeAdjust .* cw_Sweep.signal_ .* (elevation_(ii) > 0);   % Zero out if not visible.
    
      end                                                            % Repeat for all sweeps.
    
      % ROP.tau = lfmSweep.tau;                                      % Add tau to ROP structure.
      lfmSweep_ = lfmSweep.signal_;
      
    end

    %---------------------------------------------------------------------------------------------
    function elementData = inverseBeamForm( ...
        radarReturn_, ...
        ROP, ...
        azimuth_, ...
        elementLat_, ...
        elementLon_, ...
        elementAlt_)
    % Perform inverse beamforming.
    %---------------------------------------------------------------------------------------------
      nElements = length(elementLat_);                               % Number of elements.
      nSamplesPerSweep = ROP.Fs * ROP.Tau;                           % Calculate samples/sweep.
      nSamples = length(radarReturn_);                               % Number of return samples.
      nSweeps =  fix(nSamples./nSamplesPerSweep);                    % Calculate number of sweeps.

      X = elementLon_(end) - elementLon_(1);                         % Calculate antenna 
      Y = elementLat_(end) - elementLat_(1);                         % orientation relative
      antennaOrientation = atan2d( Y, X );                           % to North.

      azPlus = azimuth_ + antennaOrientation;                        % Adjust target azimuth.

      % ii = 1;                                                        % Calculate antenna
      % jj = nElements;                                                % element separation
      % [x0, y0, z0] = geodetic2ecef( wgs84Ellipsoid, ...              % based on element 
      %   elementLat_(ii), elementLon_(ii), elementAlt_(ii) );         % latitudes and 
      % [x1, y1, z1] = geodetic2ecef( wgs84Ellipsoid, ...              % longitudes.
      %   elementLat_(jj), elementLon_(jj), elementAlt_(jj) );         % 
      % separation = ...                                               % 
      %   sqrt( (x0-x1)^2 +  (y0-y1)^2 + (z0-z1)^2 )./nElements;       % 
      % 
      % strt = nElements./2 - 0.5;                                     % Calculate element offset.
      % stop = strt;                                                   %
      % elementNumber = -strt:1.0:stop;                                %
      % 
      % elementDisplacement = elementNumber .* separation;             % Calculate phase weights.
      % term1 = 2.0 .* pi .* elementDisplacement;                      %
      % elementPhaseOffset = term1 .* sind(azPlus) ./ lambda;          %
      % elementPhaseWeight = ...                                       %
      %   cos(elementPhaseOffset) + sin(elementPhaseOffset)*1i;        %

      elementPhaseWeight = ROTH.calculatePhaseWeights( ...
        azPlus, ...
        ROP.Fc, ...
        elementLat_, ...
        elementLon_, ...
        elementAlt_);

      elementData = zeros(nSamples,nElements);                       % Initialize element buffer.

      for ii = 1:nElements                                           % Perform the inverse
        for jj = 1:nSweeps                                           % beam former process.
          strt = (jj-1)*nSamplesPerSweep + 1;                        %
          stop = jj*nSamplesPerSweep;                                %
          elementSweep = ...                                         %
            elementPhaseWeight(ii).*radarReturn_(strt:stop);         %
          elementData(strt:stop,ii) = elementSweep;                  %
        end                                                          %
      end                                                            %

    end

    %---------------------------------------------------------------------------------------------
    function [lat1, lon1, lat2, lon2] = kentElementPositions()
    % Recreate element position of the Kent Virginia arrays.
    %---------------------------------------------------------------------------------------------
      lat1 = linspace( +37.56471566761531, +37.56504156214795, 16);
      lon1 = linspace( -77.02492387826882, -77.02315533241601, 16);
      
      lat2 = linspace( +37.564472026873595, +37.56463406975547, 16);
      lon2 = linspace( -77.026233994593280, -77.02535206202278, 16);
      
    end

    %---------------------------------------------------------------------------------------------
    function pulseCompress_ = matchedFilter( radarReturn_,  lfmSweep_)
    % Perform match filtering (pulse compresstion.)
    %---------------------------------------------------------------------------------------------   
      mFilter = zeros( size(radarReturn_) );                         % Initialize filter buffer.

      sweepSamples = length(lfmSweep_);                              % Get number of samples in 
                                                                     % sweep.
                                                                     
      mFilter(1:sweepSamples) = flip(conj(lfmSweep_));               % Time reverse and conj 
                                                                     % LFM sweep for matched
                                                                     % filter process.
      
      fft1 = fft(mFilter);                                           % FFT filter bank and 
      
      fft2 = fft(radarReturn_);                                      % FFT radar return 
      
      pulseCompress_ = ifft(fft1.*fft2);                             % Perform matched filter.
    end

    %---------------------------------------------------------------------------------------------
    function [lat1,lon1, lat2, lon2] = ohsElementPositions()
    % Create imaginary RADAR elements near Ohio State stadium.
    %---------------------------------------------------------------------------------------------
      [lat1, lon1, lat2, lon2] = ROTH.kentElementPositions();
    
      lat1 = lat1 + 2.443413136634668;
      lat2 = lat2 + 2.443413136634668;
      
      lon1 = lon1 - 5.992341434616776;
      lon2 = lon2 - 5.992341434616776;
    end

    %---------------------------------------------------------------------------------------------
    function rangeBinFloat = slantRange2RangeBin(slantRange, Bw, Swr, Fs)
    % Calculate range bin using:
    %   slantRange in meters.
    %   Bw  is the bandwidth of the Linear Frequency Modulated signal.
    %   Swr is sweep rate
    %   Fs  is sample rate.
    %---------------------------------------------------------------------------------------------
      secondsPerSweep = Bw./Swr;
      rangePerSweep   = UNIVERSE.C .* secondsPerSweep;
      rangePerReturn  = 0.5 * rangePerSweep;
      samplesPerSweep = Fs .* secondsPerSweep;
      rangePerBin     = rangePerReturn/samplesPerSweep;
      rangeBinFloat   = slantRange./rangePerBin;
    end
    


  end
end

