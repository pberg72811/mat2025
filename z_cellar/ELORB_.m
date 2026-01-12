rx = 6524.834;
ry = 6862.875;
rz = 6448.296;

vx = +4.901327;
vy = +5.533756;
vz = -1.976341;

[p, a, e, i, O, o, nu, omega_true, arg_lat, true_long] = ELORB(rx, ry, rz, vx, vy, vz)

function [p, a, e, i, O, o, nu, omega_true, arg_lat, true_long] = ELORB(rx, ry, rz, vx, vy, vz)
%-------------------------------------------------------------------------------------------------
% 120
%
   mu = 1.0;
   ER_Km = EARTH.RADIUS./1000;
   ER_TU = 7.905365719014;

   r_ = [rx./ER_Km, ry./ER_Km, rz./ER_Km];
   r  = sqrt( r_(1).*r_(1) + r_(2).*r_(2) + r_(3).*r_(3) );

   v_ = [vx./ER_TU, vy./ER_TU, vz./ER_TU];
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

   omega_true = acosd( e_(1)./e );

   if e_(2) < 0.0
      omega_true = 360 - omega_true;
   end

   arg_lat = acosd( dot(n_, r_)./(n.*r) );

   if r_(3) < 0.0
      arg_lat = 360 - arg_lat;
   end

   true_long = acosd( r_(1)./r );

   if r_(2) < 0.0
      true_long = 360 - true_long;
   end

end

  
