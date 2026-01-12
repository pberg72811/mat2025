classdef z_NEEDS_WORK_Planet < handle
  %------------------------------------------UNCLASSIFIED-----------------------------------------
  % Name: Planet.m
  %
  % Dscr: This is a Planet class.
  %
  % Hist: Who   When       What
  %       ptb   01/05/18   Initial code. (From Java).
  %------------------------------------------UNCLASSIFIED-----------------------------------------
  properties
    mass = 1.0;
    radius = 1.0;
  end
  
  methods (Static = true)
    
      function E1 = keplerElliptical(M, e)
      %
      %
      %
      if (((-pi < M) && (M < 0)) || (M > pi))
        E0 = M - e;
      else
        E0 = M + e;
      end
      
      E1 = E0 + (M - E0 + e * sin(E0)) / (1.0 - e * cos(E0));
      diff = E1 - E0;
      E0 = E1;
      
      while (diff > 10.0e-8)
        E1 = E0 + (M - E0 + e * sin(E0)) / (1.0 - e * cos(E0));
        diff = E1 - E0;
        E0 = E1;
      end
      
      if (E1 < 0)
        E1 = E1 + 2 * PI;
      end
            
    end
    
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
      
    %----------------------------------------------------------------%----------------------------
    function RotM = randVRotM( i_,  O,  o)                           % randVRotM
      RotM = zeros(3,3);
      RotM(1,1) = +cos(O) * cos(o) - sin(O) * sin(o) * cos(i_);
      RotM(1,2) = -cos(O) * sin(o) - sin(O) * cos(o) * cos(i_);
      RotM(1,3) = +sin(O) * sin(i_);
      RotM(2,1) = +sin(O) * cos(o) + cos(O) * sin(o) * cos(i_);
      RotM(2,2) = -sin(O) * sin(o) + cos(O) * cos(o) * cos(i_);
      RotM(2,3) = -cos(O) * sin(i_);
      RotM(3,1) = +sin(o) * sin(i_);
      RotM(3,2) = +cos(o) * sin(i_);
      RotM(3,3) = +cos(i_);
    end
    
    %----------------------------------------------------------------%----------------------------
    function result = calcNu( M,  e)                                 % calcNu
      E = keplerElliptical(M * DE2RA, e);
      sinv = (sqrt(1.0 - e * e) * sin(E)) / (1.0 - e * cos(E));
      cosv = (cos(E) - e) / (1.0 - e * cos(E));
      nu = atan2(sinv, cosv);
      if (nu < 0)
        nu = nu + 2.0 * PI;
      end
      result = nu;
      %     DEBUG.MESSAGEF("v = %23.16f or %23.16f\n", this.nu, this.nu * RA2DE);
      %     return (nu);
    end
    
  end

end
