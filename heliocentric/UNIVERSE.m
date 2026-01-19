classdef UNIVERSE < handle
%
% Class that encapsulates UNIVERSE stuff.
% The UNIVERSE is rendered in System International (SI) units.
% Seconds       Time
% Meters        Distance
% Kilograms     Mass
% Kelvin        Temperature
% Ampere        Electric Current
% Mole          Amount of substance
% Candela
% Tesla (in SI base units: kilogram per second squared per ampere)
    
   properties (Constant)
      G = 6.6743e-11;                            % m3/kg/(s*s)
      C = 299792458;                             % m/s
      e = 1.602176634e-19;                       % Elementary Charge.
   end


   methods (Static)
   
   function [p, a, e, i, O, o, nu, oTrue, argLat, trueLon] = ELORB(r_, v_)
   % p. 120
   %

      mu = 1.0;
      % ER_Km = EARTH.RADIUS./1000;
      % ER_TU = 7.905365719014;
      % r_ = [rx./ER_Km, ry./ER_Km, rz./ER_Km];
      % v_ = [vx./ER_TU, vy./ER_TU, vz./ER_TU];

      r  = sqrt( r_(1).*r_(1) + r_(2).*r_(2) + r_(3).*r_(3) );
   
      v  = sqrt( v_(1).*v_(1) + v_(2).*v_(2) + v_(3).*v_(3) );
   
      h_ = cross(r_, v_);
      h  = sqrt( h_(1).*h_(1) + h_(2).*h_(2) + h_(3).*h_(3) );
      hh = h*h;
   
      K_ = [0, 0, 1];
   
      n_ = cross(K_, h_);
      n  = sqrt( n_(1).*n_(1) + n_(2).*n_(2) + n_(3).*n_(3) );
   
      e_ = 1.0/mu .* ( (v^2 - mu./r).*r_ - (dot(r_,v_).*v_) );
      e  = sqrt( e_(1).*e_(1) + e_(2).*e_(2) + e_(3).*e_(3) );
   
      xi = (v^2./2) - (1/r);
   
      if (norm(e_) ~= 1.0)
          a = -mu./(2.0*xi);
          p = hh./mu;
      else
         a = 0;
         p = 0;
      end
   
      i = acosd( h_(3)./h );
      
      O = acosd( n_(1)./n );
      
      if n_(2) < 0.0
         % disp("NEED TO FLIP");
         O = 360 - O;
      end
   
      o = acosd( dot(n_, e_)./(n.*e) );
   
      if e_(3) < 0.0
         o = 360 - o;
      end
   
      nu = acosd( dot(e_, r_)/(e.*r) );
   
      if dot(r_,v_) < 0.0
         nu = 360 - nu;
      end
   
      oTrue = acosd( e_(1)./e );
   
      if e_(2) < 0.0
         oTrue = 360 - oTrue;
      end
   
      trueLon = acosd( dot(n_, r_)./(n.*r) );
   
      if r_(3) < 0.0
         argLat = 360 - trueLon;
      end
   
      trueLon = acosd( r_(1)./r );
   
      if r_(2) < 0.0
         trueLon = 360 - trueLon;
      end
   
   end

    function [r_, v_] = randV( p, e, i_, O, o, nu ) %---------------------------------------------
    % p. 125
    % "p" needs to be Canonical.  That is, divided by AU or ER or whatever.
    %
        x = p * cosd(nu) / (1 + e * cosd(nu));
        y = p * sind(nu) / (1 + e * cosd(nu));
        z = 0.0;
        
        vx = -sqrt(1./p).*sind(nu);
        vy = +sqrt(1./p).*(e + cosd(nu));
        vz = 0;
        
        r_ = UNIVERSE.ROT3d(-O) * UNIVERSE.ROT1d(-i_) * UNIVERSE.ROT3d(-o) * [ x;  y;  z];
        v_ = UNIVERSE.ROT3d(-O) * UNIVERSE.ROT1d(-i_) * UNIVERSE.ROT3d(-o) * [vx; vy; vz];
    end
   
    function ROT1 = ROT1r(a) %--------------------------------------------------------------------
    % For Right Handed Axis, Returns clockwise rotation matrix for X axis by angle phi in radians.
    % p. 168
    %
        ROT1 = [       1       0       0 ;
                       0 +cos(a) +sin(a) ;
                       0 -sin(a) +cos(a)];
    end
   
    function ROT2 = ROT2r(a) %--------------------------------------------------------------------
    % For Right Handed Axis, Returns clockwise rotation matrix for Y axis by angle phi in radians.
    % p.168
    %
        ROT2 = [ +cos(a)      0 -sin(a) ;
                       0      1       0 ;
                 +sin(a)      0 +cos(a)];
    end
   
    function ROT3 = ROT3r(a) %--------------------------------------------------------------------
    % For Right Handed Axis, Returns clockwise rotation matrix for Z axis by angle phi in radians.
    % p.168
        ROT3 = [ +cos(a) +sin(a)      0 ;
                 -sin(a) +cos(a)      0 ;
                       0       0      1];
    end

   function ROT1 = ROT1d(a) %---------------------------------------------------------------------
   % For Right Handed Axis, Returns clockwise rotation matrix for X axis by angle phi in degrees.
   % p. 168
   %
      ROT1 = UNIVERSE.ROT1r( deg2rad(a) );
   end

   function ROT2 = ROT2d(a) %---------------------------------------------------------------------
   % For Right Handed Axis, Returns clockwise rotation matrix for Y axis by angle phi in degrees.
   % p. 168
   %
       ROT2 = UNIVERSE.ROT2r( deg2rad(a) );
   end

   function ROT3 = ROT3d(a) %---------------------------------------------------------------------
   % For Right Handed Axis, Returns clockwise rotation matrix for Z axis by angle phi in degrees.
   % p. 168
   %
       ROT3 = UNIVERSE.ROT3r( deg2rad(a) );
   end 

   end
end