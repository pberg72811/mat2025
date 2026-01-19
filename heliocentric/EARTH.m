classdef EARTH < handle
%
% Class that encapsulates EARTH stuff.
%
    
    properties (Constant)
    %
    %
    %
        TU                     = 13.44685206374;           % TU for Earth.
        FLATTENING            =  1/298.257;                % Vallado pg. 138
        TILT                  =       23.5;                % Degrees relative to orbital plane.
        RADIUS                =  6378136.3;                % Almanac Supplement p 151.
        ACCELERATIONG         =        9.8;                % Meters/sec^2
        SECONDSPERDAY         =    86400.0;                % Seconds
        CIRCUMFERENCE         = 40075016.7;                % Meters 2*pi*RADIUS
        MASS                  = 5.97219e24;                % Kg
        
        SEMIMAJORAXIS         = 6378137;                   % From MATLAB WGS84 page.
        SEMIMINORAXIS         = 6356752.31424518;          % SEMIMINORAXIS is a derived quantity.
        INVERSEFLATTENING     = 298.257223563;             % 
        ECCENTRICITY          = 0.0818191908426215;        % 

        JULIANSECONDS1970     = 210866760000;
        JULIANSECONDS1950     = 210235608000;
        SecondsPerSiderealDay = 86164.1;
        SecondsPerSolarDay    = 86400.0;

        SYMBOL                = char(10753);               % MATLAB char EARTH symbol. ⨁
        ARIES                 = char(9800);                % MATLAB char ARIES symbol. ♈

        GROUNDZ               = [40.00166143770505, -83.01974272804372, 275.0];
        GROUNDM               = [42.26587943948621, -83.74873952908156, 230.0];

    end

    %---------------------------------------------------------------------------------------------
    methods (Static)
    %---------------------------------------------------------------------------------------------

    %---------------------------------------------------------------------------------------------
    function [lat, lon, h] = ECF2LLA_WGS(x, y, z)
    % Takes Earth Center Fixed (ECF) x,y,z coordinates in Meters and 
    % returns latitude, longitude, altitude.
    %---------------------------------------------------------------------------------------------
      rdelsat = sqrt( x.*x + y.*y );
      alpha_sin = asin(y./rdelsat);
      alpha_cos = acos(x./rdelsat);

    end

    %---------------------------------------------------------------------------------------------
    function [lat, lon, h] = ECF2LLA(x, y, z)
    % Takes Earth Center Fixed (ECF) x,y,z coordinates in Meters and 
    % returns latitude, longitude, altitude.
    %---------------------------------------------------------------------------------------------
      r = sqrt(x*x + y*y + z*z);
      lat = asin(z/r);
      lon = atan2(y,x);
      h = r - EARTH.RADIUS;
    end

    %---------------------------------------------------------------------------------------------
    function [lat, lon, h] = ECI2LLA(JD, x, y, z)
    % Takes Earth Center Inertial (ECI) x,y,z coordinates in Meters and 
    % returns latitude, longitude, altitude.
    %---------------------------------------------------------------------------------------------
      phi = EARTH.getPhiGrn(JD);
      
      [x, y, z] = xyzYawRad(x, y, z, phi);

      [lat, lon, h] = EARTH.ECF2LLA(x, y, z);
  end

    %---------------------------------------------------------------------------------------------
    function [p, a, e, i, O, o, nu, o_true, argLat, trueLon] = ELORB(rx, ry, rz, vx, vy, vz)
    % rx, ry, rz is meters.
    % vx, vy, vz is meters/second.
    %---------------------------------------------------------------------------------------------
      r_ = [rx./EARTH.RADIUS, ry./EARTH.RADIUS, rz./EARTH.RADIUS];
      
      v_ = [vx./EARTH.RADIUS/EARTH.TU, vy./EARTH.RADIUS/EARTH.TU, vz./EARTH.RADIUS/EARTH.TU];
      
      [p, a, e, i, O, o, nu, o_true, argLat, trueLon] = UNIVERSE.ELORB(r_, v_);
    end

    %---------------------------------------------------------------------------------------------
    function [x,y,z] = LLA2ECF(lat, lon, alt) 
    % Converts latitude, longitude, altitude to Earth Centered Fix (ECF) x, y, z.
    % Latitude  in Degrees
    % Longitude in Degrees
    % Altitude  in Meters
    % X, Y, Z returned as Meters
    %---------------------------------------------------------------------------------------------
      latRad = deg2rad(lat);
      lonRad = deg2rad(lon);
      R = alt + EARTH.RADIUS;
      x = cos(latRad).*cos(lonRad).*R;
      y = cos(latRad).*sin(lonRad).*R;
      z = sin(latRad).*R;
    end
    
    %---------------------------------------------------------------------------------------------
    function [X, Y, Z] = LLA2ECF_WGS(lat, lon, alt)
    % Converts latitude, longitude, altitude to Earth Centered Fix (ECF) x, y, z
    % using WGS84 SEMIMAJORAXIS and ECCENTRICITY geodetic.
    % Latitude  in Degrees
    % Longitude in Degrees
    % Altitude  in Meters
    % X, Y, Z returned as Meters
    %---------------------------------------------------------------------------------------------
      a = EARTH.SEMIMAJORAXIS;
      e = EARTH.ECCENTRICITY;
      denom = sqrt( 1.0 - e.*e.*sind(lat).*sind(lat) );
      N = a./denom;
      X = (N + alt) .* cosd(lat) .* cosd(lon);
      Y = (N + alt) .* cosd(lat) .* sind(lon);
      Z = (N .* (1.0 - e*e) + alt) .* sind(lat);
    end
    
    %---------------------------------------------------------------------------------------------
    function [x,y,z] = LLA2ECI(JD, lat, lon, alt)
    % Converts latitude, longitude, altitude to Earth Centered Fix (ECF) x, y, z.
    % Latitude  in Degrees
    % Longitude in Degrees
    % Altitude  in Meters
    % X, Y, Z returned as Meters
    %---------------------------------------------------------------------------------------------
      [x,y,z] = EARTH.LLA2ECF(lat, lon, alt);

      [x,y,z] = xyzYawRad(x, y, z, EARTH.phiGrn(JD));
   
    end

    %---------------------------------------------------------------------------------------------
    function [x,y,z] = LLA2ECI_WSG(JD, lat, lon, alt)
    % Converts latitude, longitude, altitude to Earth Centered Fix (ECF) x, y, z.
    % Latitude  in Degrees
    % Longitude in Degrees
    % Altitude  in Meters
    % X, Y, Z returned as Meters
    %---------------------------------------------------------------------------------------------
      [x,y,z] = EARTH.LLA2ECF_WGS(lat, lon, alt);

      [x,y,z] = xyzYawRad(x, y, z, EARTH.phiGrn(JD));
     
    end

    %---------------------------------------------------------------------------------------------
    function ps =  calendarTo1950Seconds(yyyy, mm, dd, hh, mn, ss)
    % Calculate Midas seconds (1950) based on Year, Month, Day, Hour, Minute, Seconds
    % using UTC timezone.
    %---------------------------------------------------------------------------------------------
        dt = datetime(yyyy, mm, dd, hh, mn, ss, "TimeZone", "UTC");
        diff = EARTH.JULIANSECONDS1970 - EARTH.JULIANSECONDS1950;
        ps = posixtime(dt) + diff;
    end

    %---------------------------------------------------------------------------------------------
    function ps =  calendarTo1970Seconds(yyyy, mm, dd, hh, mn, ss) 
    % Calculate POSIX seconds (1970) based on Year, Month, Day, Hour, Minute, Seconds
    % using UTC timezone.
    %---------------------------------------------------------------------------------------------
        dt = datetime(yyyy, mm, dd, hh, mn, ss, "TimeZone", "UTC");
        
        ps = posixtime(dt);
    end

    %---------------------------------------------------------------------------------------------
    function JD =  calendarToJulianDay(yyyy, mm, dd, hh, mn, ss) 
    % Calculate Julian Day based on Year, Month, Day, Hour, Minute, Seconds using UTC timezone.
    % (1996,10,26,14,20,00) = 2450383.09722222
    %---------------------------------------------------------------------------------------------
        js = EARTH.calendarToJulianSeconds(yyyy, mm, dd, hh, mn, ss);
        
        JD = js ./ EARTH.SecondsPerSolarDay;
    end

    %---------------------------------------------------------------------------------------------
    function js =  calendarToJulianSeconds(yyyy, mm, dd, hh, mn, ss) 
    % Calculate Julian seconds based on Year, Month, Day, Hour, Minute, Seconds
    % using UTC timezone.
    %---------------------------------------------------------------------------------------------
        js = EARTH.calendarTo1970Seconds(yyyy, mm, dd, hh, mn, ss) + EARTH.JULIANSECONDS1970;
    end

    %---------------------------------------------------------------------------------------------
    function ms = current1950Seconds() 
    % Calculate currently Midas (1950) seconds.
    %---------------------------------------------------------------------------------------------
        diff = EARTH.JULIANSECONDS1970 - EARTH.JULIANSECONDS1950;
        ms = EARTH.current1970Seconds() + diff;
    end

    %---------------------------------------------------------------------------------------------
    function ps = current1970Seconds() 
    % Get current POSIX (1970) Seconds.
    %---------------------------------------------------------------------------------------------
        dt = datetime('now', 'TimeZone', 'UTC');
        
        ps = posixtime(dt);
    end

    %---------------------------------------------------------------------------------------------
    function js = currentJulianSeconds()
    % Get current Julian Seconds.
    %---------------------------------------------------------------------------------------------
        js = EARTH.current1970Seconds() + EARTH.JULIANSECONDS1970;
    end

    %---------------------------------------------------------------------------------------------
    function jd = currentJulianDay() 
    % Get current Julian Day.
    %---------------------------------------------------------------------------------------------
        js = EARTH.currentJulianSeconds();

        jd = js ./ EARTH.SecondsPerSolarDay;
    end

    %---------------------------------------------------------------------------------------------
    function phi = currentPhiGrn() 
    % Get the current hour angle
    %---------------------------------------------------------------------------------------------
        JD = EARTH.currentJulianDay();
        
        phi = EARTH.phiGrn(JD);
    end

    %---------------------------------------------------------------------------------------------
    function result = phiGrn(JD) 
    % Return current Greenwich Hour Angle (GHA) in radians.
    % Fundamentals of Astrodynamics and Applications (2nd Ed), David A. Vallado page 212.
    % Seems to be off by 40 seconds compared to one source.
    %---------------------------------------------------------------------------------------------
        t1 = 0.7790572732640;                                        % Hour Angle Calculation.
        t2 = 1.00273781191135448;                                    %
        t3 = JD - 2451545.0;                                         %
        result = 2.0 * pi * ( t1 + ( t2 * t3 ) );                    %
        result = mod( result, 2 * pi );                              %
    end

    %---------------------------------------------------------------------------------------------
    function [x,y,z] = positionVector(JD) 
    % Return the position of the Earth relative to the Sun.
    %---------------------------------------------------------------------------------------------
         [x,y,z] = SUN.positionVector(JD);
         x = -x;
         y = -y;
         z = -z;
    end

    %---------------------------------------------------------------------------------------------
    function [r_, v_] = randV( p_meters, e, i_, O, o, nu )
    % 125
    %---------------------------------------------------------------------------------------------
        p = p_meters./EARTH.RADIUS;
        
        [r_, v_] = randV1( p, e, i_, O, o, nu );
    end


    %---------------------------------------------------------------------------------------------
    %---------------------------------------------------------------------------------------------
    % Some minor methods.
    %---------------------------------------------------------------------------------------------
    %---------------------------------------------------------------------------------------------


    function plotCircle()
    %---------------------------------------------------------------------------------------------
    % Plot the circle of the Earth.
    %
        xc = 0.0;
        yc = 0.0;
        theta = linspace(0,2*pi);
        x = EARTH.RADIUS * cos(theta) + xc;
        y = EARTH.RADIUS * sin(theta) + yc;
        plot(x,y);
        axis equal;
    end
    
    function plotEllipse()
    %---------------------------------------------------------------------------------------------
    % Plot the ellipsoid of the Earth.
    %
        c = EARTH.SEMIMAJORAXIS * EARTH.ECCENTRICITY;
        EE2 = EARTH.ECCENTRICITY * EARTH.ECCENTRICITY;
        A2  = EARTH.SEMIMAJORAXIS * EARTH.SEMIMAJORAXIS;
        b = sqrt( (1 - EE2) * A2 );
        disp([b c])
        xc = 0.0;
        yc = 0.0;
        
        theta = linspace(0,2*pi);
        x = EARTH.SEMIMAJORAXIS * cos(theta) + xc;
        y = EARTH.SEMIMINORAXIS * sin(theta) + yc;
        plot(x,y);
        axis equal;
      end
      

      
    end
end

% function [N_h, U_h]  = northVector(lat, lon, alt)
% %---------------------------------------------------------------------------------------------
% % 
% % Experimental.
% %      
%     altNew = ( EARTH.RADIUS./cosd(1.0) ) - EARTH.RADIUS;
%     [x0, y0, z0] = EARTH.LLA2ECF(lat, lon, alt .* 0.0);
%     [x1, y1, z1] = EARTH.LLA2ECF(lat+1.0, lon, altNew);
%     plot3( [0 x0], [0 y0], [0 z0], 'b' );
%     pause(1)
%     hold on
%     plot3( [ 0 x1], [ 0 y1], [ 0 z1], 'b' );
%     pause(1)
%     plot3( [x0 x1], [y0 y1], [z0 z1], 'r');
%     pause(1)
%     [x2, y2, z2] = EARTH.LLA2ECF(lat, lon, alt+1e6);
%     plot3( [x0 x2], [y0 y2], [z0 z2], 'r');
% 
%     hold off
%     N_ = [ (x1  - x0) (y1  - y0)  (z1  - z0) ];
%     N = norm(N_);
%     N_h = N_ ./ N;
% 
%     U_ = [x0, y0, z0];
%     U_h = U_ ./ norm(U_);
% end

% function [lat, lon, h] = ECF2LLA_PY(x, y, z) %------------------------------------------------
% %---------------------------------------------------------------------------------------------
% % Takes Earth Center Fixed (ECF) x,y,z coordinates in Meters and 
% % returns latitude, longitude, altitude. *** PYTHON ***
% %      
%    tmp = double( py.xpy.EARTH.ECF2LLA(x, y, z) );
%    lat = tmp(1);
%    lon = tmp(2);
%    h   = tmp(3);
% end
% 
% function [lat, lon, h] = ECI2LLA_PY(JD, x, y, z) %--------------------------------------------
% % Takes Earth Center Inertial (ECI) x,y,z coordinates in Meters and 
% % returns latitude, longitude, altitude.
% %
%     tmp = double( py.xpy.EARTH.ECI2LLA(JD, x, y, z) );
%     lat = tmp(1);
%     lon = tmp(2);
%     h   = tmp(3);
% end
% 
% 
% function JD =  calendarToJulianDay_PY(yyyy, mm, dd, hh, mn, ss) %-----------------------------
% % Calculate Julian Day based on Year, Month, Day, Hour, Minute, Seconds
% % using UTC timezone. (1996,10,26,14,20,00) = 2450383.09722222. ** PYTHON **
% %
%     JD = py.xpy.EARTH.calendarToJulianDay( yyyy, mm, dd, hh, mn, ss );
% end
% 
% function js = currentJulianSeconds_PY() %-----------------------------------------------------
% % Get current Julian Seconds. ** PYTHON **
% %        
%     js = py.xpy.EARTH.currentJulianSeconds();
% end
% 
% 
% function jd = currentJulianDay_PY() %---------------------------------------------------------
% % Get current Julian Day. ** PYTHON **
% %    
%     jd = py.xpy.EARTH.currentJulianDay();
% end
% 
% 
% function phi = currentPhiGrn_PY() %-----------------------------------------------------------
% % Get the current hour angle. ** PYTHON **
% %    
%     phi = py.xpy.EARTH.currentPhiGrn();
% end
% 
% 
% function phi = phiGrn_PY(JD) %----------------------------------------------------------------
% % Get the current hour angle
% %    
%     phi = py.xpy.EARTH.phiGrn(JD);
% end