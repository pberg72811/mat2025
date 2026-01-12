%--------------------------------UNCLASSIFIED----------------------------------
% Name: uCalcDirCos.m
%
% Synt: function [alpha, beta, gamma, earthObscured] =...
%                                  uCalcDirCos(Sat1XYZ, Sat1VxVyVz, Sat2XYZ);
%
% Dscr: This calculates direction cosines based on Satellite 1 Position
%       Vector, Satellite 1 Velocity Vector, and Satellite 2 Position
%       Vector.
%
% Ins : Sat1XYZ     Satellite 1 Position vector ([x y z]).
%       Sat1VxVyVz  Satellite 1 Velocity vector ([x y z]).
%       Sat2XYZ     Satellite 2 Position vector ([x y z]).
%
% Outs: alpha
%       beta
%       gamma
%       earthObscure
%
% Hist: Who   When       What
%       ptb   3/08/99   Derived from RMcOmber code.  Checked with WSC data
%                       for XTE on 8/5/98 16:48-17:41.   :)
%--------------------------------UNCLASSIFIED----------------------------------
function [alpha, beta, gamma, earthObscured] = uCalcDirCos(Sat1XYZ, Sat1VxVyVz, Sat2XYZ);

%------------------------------------------------------------------------------
% Difference Vector between the two sats.
%------------------------------------------------------------------------------
  diff = Sat2XYZ - Sat1XYZ;
  magDiff = sqrt(sum(diff.^2));
  normDiff = diff./magDiff;

%------------------------------------------------------------------------------
% zAxis is pointed at center of earth (NADIR).
%------------------------------------------------------------------------------
  magSat1 = sqrt(sum(Sat1XYZ.^2));
  normSat1 = Sat1XYZ./magSat1;
  zAxis = -normSat1;

%------------------------------------------------------------------------------
% xAxis.  Velocity vector minus a pinch.
%------------------------------------------------------------------------------
  temp = sum(Sat1VxVyVz.*zAxis);
  xAxis = Sat1VxVyVz - temp .* zAxis;
  xAxis = xAxis./sqrt(sum(xAxis.^2));

%------------------------------------------------------------------------------
% yAxis is cross product of zAxis and xAxis.
%------------------------------------------------------------------------------
  yAxis = cross(zAxis, xAxis);
  yAxis = yAxis./sqrt(sum(yAxis.^2));

%------------------------------------------------------------------------------
% Calculate direction cosines.  Dot product of difference vector and each axis.
%------------------------------------------------------------------------------
  alpha = sum(normDiff.*xAxis);
  beta  = sum(normDiff.*yAxis);
  gamma = sum(normDiff.*zAxis);

%------------------------------------------------------------------------------
% Check to see if the Earth is obscuring the view.
%------------------------------------------------------------------------------
  theta = acos(gamma);
  a = magSat1;
  b = a ./ cos(theta);
  c = b .* sin(theta);
  
  if( (c < 6378.135) & (a < magDiff) ) earthObscured = 1;
  else earthObscured = 0;
  end
