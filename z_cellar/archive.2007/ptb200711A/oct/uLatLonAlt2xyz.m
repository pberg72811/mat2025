%--------------------------------UNCLASSIFIED----------------------------------
% Name: uLatLonAlt2xyz.m
%
% Auth: Paul Bergman, Stel.
%
% Dscr: This functions calculates an x, y, and z position in Earth-Centered
%       Earth-Fixed coordinates given a Latitude, Longitude, and Altitude.
%
% Ins :  Lat
%        Lon
%        Alt
%
% Outs: X
%       Y
%       Z
%
% Hist: Who   When       What
%       ptb   9/16/98   Initial code.
%--------------------------------UNCLASSIFIED----------------------------------
function [X, Y, Z] = uLatLonAlt2xyz(Lat,Lon,Alt);
DTR = pi/180;
Re = 6378.135;
R = Alt + Re;

X = cos(Lat*DTR).*cos(Lon*DTR).*R;
Y = cos(Lat*DTR).*sin(Lon*DTR).*R;
Z = sin(Lat*DTR).*R;
