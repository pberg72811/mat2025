%--------------------------------UNCLASSIFIED----------------------------------
% Name: amp2dB.m
%
% Auth: Paul Bergman, Stel.
%
% Dscr: This function makes a conversion from linear amplitude to 
%       units in dB.
%
% Ins : amp              Number assumed to be an amplitude
%
% Outs: dB               Number converted to dB 
%
% Hist: Who   When       What
%       ptb   11/12/97   Initial code.
%--------------------------------UNCLASSIFIED----------------------------------
  function dB = amp2dB( amp );

  dB = 10.0 .* log10(amp);
