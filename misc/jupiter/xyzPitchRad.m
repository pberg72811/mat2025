function [x,y,z] = xyzPitchRad(x, y, z, a_) 
%
% 
%
   pitchMatrix = [  cos(a_)  0 -sin(a_);
                      0      1    0    ;
                    sin(a_)  0  cos(a_)];

   res =  pitchMatrix * [x; y; z];
   
   x = res(1);
   y = res(2);
   z = res(3);
end