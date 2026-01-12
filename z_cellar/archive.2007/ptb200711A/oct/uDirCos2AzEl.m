function [Az, El] = uDirCos2AzEl(Alpha, Beta, Gamma);
%--------------------------------UNCLASSIFIED----------------------------------
% Name: uDirCos2AzEl.m
%
% Auth: Paul Bergman, Stel.
%
% Dscr: This functions calculates an azimuth angle Az and an off-boresight 
%       angle El given direction cosines Alpha, Beta, Gamma. 
%       ******** CAUTION ******** CAUTION ********
%       El is an Off-boresight angle not true Elevation.
%       ******** CAUTION ******** CAUTION ********
%
% Ins : Alpha   X component direction cosine.
%       Beta    Y component direction cosine.
%       Gamma   Z component direction cosine.
%
% Outs: Az      Azimuth angle.
%       El      Off-boresight angle.
%
% Hist: Who   When       What
%       ptb   9/16/98   Initial code.
%--------------------------------UNCLASSIFIED----------------------------------

El = acos(Gamma);

Az = atan2(Beta,Alpha);
