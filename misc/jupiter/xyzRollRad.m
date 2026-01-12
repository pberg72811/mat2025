function [x,y,z] = xyzRollRad(x, y, z, a_) 
%
%
%
   rollMatrix = [  1    0        0    ;
                   0  cos(a_)  sin(a_);
                   0 -sin(a_)  cos(a_)];

   res =  rollMatrix * [x; y; z];
   
   x = res(1);
   y = res(2);
   z = res(3);
end

