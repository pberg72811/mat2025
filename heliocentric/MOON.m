classdef MOON < handle
   %------------------------------------------UNCLASSIFIED----------------------------------------
   % Name: Moon.m
   %
   % Dscr: This the Moon class.
   %
   % Hist: Who   When       What
   %       ptb   01/05/18   Initial code. (From Java).
   %------------------------------------------UNCLASSIFIED----------------------------------------
   properties
      mass = 7.34767309e22;
      radius  = 1737400;
      radiusa = 1738100;
      radiusb = 1736000;
      SYMBOL = char(9680);      % MATLAB char Moon symbol. ◐
  end
  
  methods (Static = true)
    
      function [x,y,z] =  positionVector(jd)
      %-------------------------------------------------------------------------------------------
      % Position vector of sun given Julian Day.
      % Fundamentals of Astrodynamics and Applications (2nd Ed), David A. Vallado page 268.      
      %
         DE2RA = deg2rad(1.0);
         
         if (jd == 0)
            JD = EARTH.getCurrentJulianDay();
         else
            JD = jd;
         end
         
         TTDB = (JD - 2451545.0) / 36525;
         
         lambda = 218.32...
           + (481267.883 * TTDB)...
           + 6.29 * sin((134.9 + 477198.85 * TTDB) * DE2RA)...
           - 1.27 * sin((259.2 - 413335.38 * TTDB) * DE2RA)...
           + 0.66 * sin((235.7 + 890534.23 * TTDB) * DE2RA)...
           + 0.21 * sin((269.9 + 954397.70 * TTDB) * DE2RA)...
           - 0.19 * sin((357.5 + 35999.050 * TTDB) * DE2RA)...
           - 0.11 * sin((186.6 + 966404.05 * TTDB) * DE2RA);
         
         lambda = mod(lambda,360);
         
         phi = 5.13 * sin((93.30 + 483202.03 * TTDB) * DE2RA)...
           + 0.28 * sin((228.2 + 960400.87 * TTDB) * DE2RA)...
           - 0.28 * sin((318.3 + 6003.1800 * TTDB) * DE2RA)...
           - 0.17 * sin((217.6 - 407332.20 * TTDB) * DE2RA);
         
         phi = mod(phi,360);
         
         p = 0.9508 ...
           + 0.0518 * cos((134.9 + 477198.85 * TTDB) * DE2RA) ...
           + 0.0095 * cos((259.2 - 413335.38 * TTDB) * DE2RA) ...
           + 0.0078 * cos((235.7 + 890534.23 * TTDB) * DE2RA) ...
           + 0.0028 * cos((269.9 + 954397.70 * TTDB) * DE2RA);
         
         eps = 23.439291 ...
           - 0.0130042 * TTDB ...
           - 1.6400e-7 * TTDB * TTDB ...
           + 5.0400e-7 * TTDB * TTDB * TTDB;
         
         r = 1.0 / sin(p * DE2RA);
         
         rx = r * cos(phi * DE2RA) * cos(lambda * DE2RA);
         ry = r * cos(eps * DE2RA) * cos(phi * DE2RA) * sin(lambda * DE2RA) ...
           - r * sin(eps * DE2RA) * sin(phi * DE2RA);
         rz = r * sin(eps * DE2RA) * cos(phi * DE2RA) * sin(lambda * DE2RA) ...
           + r * cos(eps * DE2RA) * sin(phi * DE2RA);
         
         result = [rx ry rz];
         
       end
       
       %-------------------------------------------------------------%----------------------------
       function test
         Moonr = Moon.positionVector( EARTH.getJulianDay(1994, 4, 28, 0, 0, 0) );
         if( ( (abs(Moonr(1) - -21.0470851)) < 0.000001) & ...
             ( (abs(Moonr(2) - -48.8499044)) < 0.000001) & ...
             ( (abs(Moonr(3) - -19.8637462)) < 0.000001))
           DEBUG.MESSAGEF('Moon Position Vector Passes:');
           DEBUG.MESSAGEF('Moon x is: %+10.8f (ER)', Moonr(1));
           DEBUG.MESSAGEF('Moon y is: %+10.8f (ER)', Moonr(2));
           DEBUG.MESSAGEF('Moon z is: %+10.8f (ER)', Moonr(3));
         end
         Moonr = Moon.currentVector();
         DEBUG.MESSAGEF('Moon Current Position Vector:');
         DEBUG.MESSAGEF('Moon x is: %+10.8f (ER)', Moonr(1));
         DEBUG.MESSAGEF('Moon y is: %+10.8f (ER)', Moonr(2));
         DEBUG.MESSAGEF('Moon z is: %+10.8f (ER)', Moonr(3));
       end
       
     end
end