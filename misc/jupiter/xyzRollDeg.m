function [x,y,z] = xyzRollDeg(x, y, z, alpha)
%
%
%
   
   a_ = deg2rad(alpha);

   [x,y,z] = xyzRollRad(x,y,z,a_);

end

