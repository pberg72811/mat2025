 [r_, v_] = randV1(11067.790, 0.83285, 87.87, 227.89, 53.38, 92.335)

function [r_, v_] = randV1( p, e, i_, O, o, nu )                    % randV1
%
%
%

   ER_Km = EARTH.RADIUS./1000;

   p = p./ER_Km;

   x = p * cosd(nu) / (1 + e * cosd(nu));
   y = p * sind(nu) / (1 + e * cosd(nu));
   z = 0.0;

   vx = -sqrt(1./p).*sind(nu);
   vy = +sqrt(1./p).*(e + cosd(nu));
   vz = 0;

   r_ = ROT3d(-O) * ROT1d(-i_) * ROT3d(-o) * [x; y; z];
   v_ = ROT3d(-O) * ROT1d(-i_) * ROT3d(-o) * [vx; vy; vz];
   
end

function ROT1_ = ROT1d(a)
%
%
%
   ROT1_ = [     1        0        0 ;
                 0 +cosd(a) +sind(a) ;
                 0 -sind(a) +cosd(a)];
end

function ROT2_ = ROT2d(a)
%
%
%
   ROT2_ = [+cosd(a)      0 -sind(a) ;
                   0      1        0 ;
            +sind(a)      0 +cosd(a)];
end

function ROT3_ = ROT3d(a)
%
%
%
   ROT3_ = [+cosd(a) +sind(a)      0 ;
            -sind(a) +cosd(a)      0 ;
                   0        0      1];
end