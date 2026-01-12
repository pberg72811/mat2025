function [x,y,z] = xyzPitchDeg(x, y, z, alpha)
%
%
%
   a_ = deg2rad(alpha);

   [x,y,z] = xyzPitchRad(x,y,z,a_);
   
end