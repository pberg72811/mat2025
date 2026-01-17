classdef SUN < handle
%
% Class that encapsulates SUN stuff.
%
    
    properties (Constant)
        MASS   = 1.9885e30                       % Kilograms
        RADIUS =  695700000.0;                   % Meters
        AU     = 149597870700;                   % Meters.
        TU     = 58.1324409;                     %
        SYMBOL = char(10752);                    % MATLAB char Sun symbol. ⨀
    end
   
   methods (Static)

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
            
            TUT1 = (JD - 2451545.0) / 36525;
            meanLongitudeOfSun = 280.460 + 36000.770 * TUT1;
            meanLongitudeOfSun = mod(meanLongitudeOfSun, 360.0);
            if (meanLongitudeOfSun < 0)
                meanLongitudeOfSun = meanLongitudeOfSun + 360.0;
            end
            
            TTDB = TUT1;
            
            meanAnomalyOfSun = 357.5277233 + 35999.05034 * TTDB;
            meanAnomalyOfSun = mod(meanAnomalyOfSun, 360.0);
            if meanAnomalyOfSun < 0
                meanAnomalyOfSun = meanAnomalyOfSun + 360.0;
            end
            
            Term2 = 1.914666471 * sin(meanAnomalyOfSun * DE2RA);
            Term3 = 0.019994643 * sin(2 * meanAnomalyOfSun * DE2RA);
            eclipticLatitude = meanLongitudeOfSun + Term2 + Term3;
            
            Term2 = 0.016708617 * cos(meanAnomalyOfSun * DE2RA);
            Term3 = 0.000139589 * cos(2 * meanAnomalyOfSun * DE2RA);
            r_ = 1.000140612 - Term2 - Term3;
            
            obliquityOfEcliptic = 23.439291 - 0.0130042 * TTDB;
            obliquityOfEcliptic = mod(obliquityOfEcliptic, 360.0);
            if obliquityOfEcliptic < 0
                obliquityOfEcliptic = obliquityOfEcliptic + 360.0;
            end
            
            x = r_ * cos( eclipticLatitude * DE2RA );
            
            y = r_ * cos( obliquityOfEcliptic * DE2RA ) * sin( eclipticLatitude * DE2RA );
            
            z = r_ * sin( obliquityOfEcliptic * DE2RA ) * sin( eclipticLatitude * DE2RA );
        end

    function [p, a, e, i, O, o, nu, oTrue, argLat, trueLon] = ELORB(rx, ry, rz, vx, vy, vz)
    %---------------------------------------------------------------------------------------------
    %
    %
        r_ = [rx./AU, ry./AU, rz./AU];
        
        v_ = [vx/AU/TU, vy/AU/TU, vz/AU/TU];
        
        [p, a, e, i, O, o, nu, oTrue, argLat, trueLon] = UNIVERSE.ELORB(r_, v_);
    end
      
    function [r_, v_] = randV( p_meters, e, i_, O, o, nu )
    %---------------------------------------------------------------------------------------------
    % 125
    %
        p = p_meters./AU;
        [r_, v_] = UNIVERSE.randV( p, e, i_, O, o, nu );
        v_ = v_/TU;
    end

   end

end