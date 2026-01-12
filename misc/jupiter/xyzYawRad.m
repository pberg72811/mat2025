function [x,y,z] = xyzYawRad(x, y, z, a_)
%-------------------------------------------------------------------------------------------
% Counter Clockwise looking down on (x,y) plane.
%
   yawMatrix = [ cos(a_) -sin(a_)  0;                     % Flip signs on the sines
                 sin(a_)  cos(a_)  0;                     % to go the "other" way.
                     0        0    1];                    % 

   res =  yawMatrix * [x; y; z];
   
   x = res(1);
   y = res(2);
   z = res(3);
end

