classdef lfmSweepClass < handle
%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: lfmSweepClass.m
%
% Dscr: Creates a LFM sweep object.
%
% Hist: Who   When       What
%       ptb   09/24/25   Initial code.
%-------------------------------------------------------------------------------------------------
  properties %====================================================================================
    fs;                  % Sample rate.
    sbw;                 % Sweep bandwidth.
    swr;                 % Sweep rate.
    tau;                 % Time of sweep in seconds.
    ts_;                 % Time series array.
    theta_;              % Angle Buffer/Array.
    signal_;             % Buffer/Array for sweep signal.
  end

  methods %=======================================================================================

    function obj = lfmSweepClass(fs, sbw, swr)
    % Constructor.
    %

      tau = sbw./swr;                                      % Time of sweep.

      ns = floor(tau*fs);                                  % Number of samples per sweep.

      ts_ = linspace( 0, tau-1/fs, ns ).';                 % Time series of sweep.

      theta_ = pi * sbw/tau * ts_.*ts_;                    % Angle series of sweep.

      theta_ = mod(theta_,2*pi);                           % Keep angle between -2*pi and +2*pi.

      obj.signal_ = cos(theta_) + sin(theta_)*1j;          % Generate complex LFM sweep.

      obj.fs  = fs;
      obj.ts_ = ts_;
      obj.sbw = sbw;
      obj.swr = swr;
      obj.tau = tau;
      obj.theta_ = theta_;

    end

    function obj = plotIt(obj)
    % A plot function for the object that is created.
    %
      plot(obj.ts_, real(obj.signal_))
      hold on
      plot(obj.ts_, imag(obj.signal_))
      hold off
    end

  end  

end


%        1         2         3         4         5         6         7         8         9
%2345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
%                                                |
