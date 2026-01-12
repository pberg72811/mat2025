classdef cwSignalClass < handle
%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: cwSignalClass.m
%
% Dscr: Creates a complex continuous wave (CW) signal give sample rate, 
% center frequency, and number of samples.
%
% Hist: Who   When       What
%       ptb   09/24/25   Initial code.
%-------------------------------------------------------------------------------------------------
  properties %====================================================================================
    fs;                      % Sample rate.
    fc;                      % Carrier frequency.
    ns;                      % Number of samples.
    dt;                      % Time of signal in seconds.
    off;
    phs;                     % Phase for phase tracking.
    tau;
    ts_;                     % Time array.
    signal_;                 % Signal Buffer/Array.
  end

  methods %=======================================================================================

    function obj = cwSignalClass(fs, fc, ns)
    % Constructor. Where:
    %   fs is sample rate. 
    %   fc is center frequency. 
    %   ns is number of samples.
    %---------------------------------------------------------------------------------------------
      obj.fs = fs;
      obj.phs = 0.0;

      obj.genSignal(fc, ns);

    end

    function obj = genSignal(obj, fc, ns)
    % Generate the signal where:
    %   fc is center frequency.
    %   ns is number of samples.
    %---------------------------------------------------------------------------------------------
      delta = 2 .* pi .* fc ./ obj.fs;                     % Radians per sample.

      theta_ = delta .* ( 0:(ns-1) ) + obj.phs;            % Array of angles.
      
      theta_ = mod(theta_, 2.*pi);                         % Keep angle between -2*pi and +2*pi;
      
      obj.signal_ = ( cos(theta_) + sin(theta_)*1j ).';    % Generate complex CW signal.

      obj.fc  = fc;                                        % Current CW frequency.
      obj.ns  = ns;                                        % Current number of samples.
      obj.phs = theta_(end);                               % Keep track of phase.

      obj.tau = obj.ns/obj.fs;                             % Duration of signal.
      obj.off = obj.tau - (1/obj.fs);                      % Time offset of signal.
      obj.ts_ = linspace( 0, obj.off, obj.ns ).';          % Time series between 0.0 and offset.

    end


    function obj = plotIt(obj)
    % A plot function for the object that is created.
    %---------------------------------------------------------------------------------------------
      plot( obj.ts_, real(obj.signal_) )
      hold on
      plot( obj.ts_, imag(obj.signal_) )
      hold off
    end

  end

end


%        1         2         3         4         5         6         7         8         9
%2345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
%                                                |



      % delta = 2 .* pi .* fc ./ fs;                         % Radians per sample.
      % 
      % theta_ = delta .* ( 0:(ns-1) );                      % Array of angles.
      % 
      % theta_ = mod(theta_, 2.*pi);                         % Keep angle between -2*pi and +2*pi;
      % 
      % obj.signal_ = ( cos(theta_) + sin(theta_)*1j ).';    % Generate complex CW signal.
      % 
      % obj.fs  = fs;
      % obj.fc  = fc;
      % obj.ns  = ns;
      % obj.phs = theta_(end);                               % Keep track of phase.
      % obj.delta = delta;
      % 
      % obj.tau = ns/fs;                                     % Time of signal.
      % obj.off = obj.tau - (1/obj.fs);                      % Time offset of signal.
      % obj.ts_ = linspace( 0, obj.off, obj.ns ).';          % Time series between 0.0 and offset.
