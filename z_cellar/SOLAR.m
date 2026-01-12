classdef SOLAR < handle
%
% Class that encapsulates SOLAR System stuff.
%
    
   properties (Constant)
      G = 6.6743e-11;                            % m3/kg/(s*s).
      C = 299792458;                             % m/s.
      AU = 149597870700;                         % Meters.
      TU = 58.1324409;                           %
   end

   methods (Static)

      function [p, a, e, i, O, o, nu, oTrue, argLat, trueLon] = ELORB(rx, ry, rz, vx, vy, vz)
      %-------------------------------------------------------------------------------------------
      %
      %
         r_ = [rx./SOLAR.AU, ry./SOLAR.AU, rz./SOLAR.AU];

         v_ = [vx/SOLAR.AU/SOLAR.TU, vy/SOLAR.AU/SOLAR.TU, vz/SOLAR.AU/SOLAR.TU];

         [p, a, e, i, O, o, nu, oTrue, argLat, trueLon] = UNIVERSE.ELORB(r_, v_);
      end
      
      function [r_, v_] = randV( p_meters, e, i_, O, o, nu )
      %-------------------------------------------------------------------------------------------
      % 125
      %
         p = p_meters./SOLAR.AU;
         [r_, v_] = UNIVERSE.randV( p, e, i_, O, o, nu );
         v_ = v_/SOLAR.TU;
      end
      

   end
end