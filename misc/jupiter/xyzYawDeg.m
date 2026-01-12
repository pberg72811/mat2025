function [x,y,z] = xyzYawDeg(x, y, z, alpha)
%-------------------------------------------------------------------------------------------
%
%
   a_ = deg2rad(alpha);
   
   [x, y, z] = xyzYawRad(x, y, z, a_);
   
end

