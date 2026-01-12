function [Alpha, Beta, Gamma] = uAzEl2DirCos(Az,El);
%--------------------------------UNCLASSIFIED----------------------------------
% Name: uAzEl2DirCos.m
%
% Auth: Paul Bergman, Stel.
%
% Dscr: This functions calculates direction cosines Alpha, Beta, Gamma
%       based on Azimuth and Elevation angles.
%       ******** CAUTION ******** CAUTION ********
%       El is an Off-boresight angle not true Elevation.
%       ******** CAUTION ******** CAUTION ********
%
% Ins:  Az      Azimuth angle.
%       El      Off-boresight angle.
%
% Outs: Alpha   X component direction cosine.
%       Beta    Y component direction cosine.
%       Gamma   Z component direction cosine.
%
%
% Hist: Who   When       What
%       ptb   9/16/98   Initial code.
%--------------------------------UNCLASSIFIED----------------------------------
Alpha = sin(El).*cos(Az);
Beta  = sin(El).*sin(Az);
Gamma = cos(El);