%--------------------------------UNCLASSIFIED----------------------------------
% Name: uXYZ2LatLonAlt.m
%
% Auth: Amit Bansal, Stel.
%
% Dscr: This function calculates the Angular co-ordinates and 
%       the Altitude for given input of Earth-Centered Earth-Fixed
%       co-ordinates (x, y, z).
%
% Ins : x     X coordiante of point of interest.
%       y     Y coordiante of point of interest.
%       z     Z coordiante of point of interest.
%
% Outs: Lat   Latitude of point of interest.
%       Lon   Longitude of point of interest.
%       Alt   Altitude of point of interest.
%
% Hist: Who   When       What
%       ab   09/16/98   Initial code.
%--------------------------------UNCLASSIFIED----------------------------------
function [Lat, Lon, Alt] = uXYZ2LatLonAlt(X, Y, Z);

%------------------------------------------------------------------------------
% Radius of earth in kilometers
%------------------------------------------------------------------------------
Re = 6378.135;

%------------------------------------------------------------------------------
% Calculating the longitude in radians for given Y and X values.
%------------------------------------------------------------------------------
Lon = atan2(Y,X)*180/pi;

%------------------------------------------------------------------------------
% Calculating the hypotenuse in terms of distance for given X and Y values.
%------------------------------------------------------------------------------
hyp = sqrt(X.^2 + Y.^2);

%------------------------------------------------------------------------------
% Calculating the Latitude in  radians for given Z and hypoteueus values.
%------------------------------------------------------------------------------
Lat = atan(Z./hyp)*180/pi;

%------------------------------------------------------------------------------
% Calculating the Radius R (Including the Altitude from zero level of earth)
% in terms of distance for given Y and Z values.
%------------------------------------------------------------------------------
R = sqrt(Y.^2 + X.^2 + Z.^2);

%------------------------------------------------------------------------------
% Calculating the Altitude in terms of distance for given R and Re values.
%------------------------------------------------------------------------------
Alt = (R - Re);
