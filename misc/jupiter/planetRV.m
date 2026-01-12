function [r_, v_] = planetRV( yyyy, M, D, h, m, s, whichPlanet)
%-------------------------------------------------------------------------------------------------
% Vallado p.285
%
    test = upper(char(whichPlanet));
    JD = EARTH.calendarToJulianDay(yyyy, M, D, h, m, s);
    
    TTDB = (JD - 2451545.0 ) ./ 36525;  % Vallado p.188
    TTDB2 = TTDB * TTDB;
    TTDB3 = TTDB * TTDB * TTDB;

    if  sum(test(1:2) == 'ME') == 2                                  % Mercury
        am =   0.387098310;
        em =   0.205631750;
        im =   7.004986000;
        Om =  48.330893000;  % Ω char(937)
        om =  77.456119000;  % ω char(969)
        lm = 252.250906000;
        
        a  = am;
        e  = em + (0.000020406 * TTDB) - (0.000000028 * TTDB2) - (0.00000000017 * TTDB3);
        i_ = im - (0.005951600 * TTDB) + (0.000000810 * TTDB2) + (0.00000004100 * TTDB3);
        O  = Om - (0.125422900 * TTDB) - (0.000088330 * TTDB2) - (0.00000019600 * TTDB3);
        o_ = om + (0.158864300 * TTDB) - (0.000013430 * TTDB2) + (0.00000003900 * TTDB3);
        lM = lm + (149472.674635*TTDB) - (0.000005350 * TTDB2) + (0.00000000200 * TTDB3); 

    elseif  test(1) == 'E'                                           % EARTH
        aE =   1.000001018;
        eE =   0.016708620;
        iE =   0.000000000;
        OE =   0.000000000;
        oE = 102.937348000;
        lm = 100.466449000;
        
        a  = aE;
        e  = eE - 0.000042037 * TTDB - 0.0000001236 * TTDB2 + 0.00000000004 * TTDB3;
        i_ = iE + 0.013054600 * TTDB - 0.0000093100 * TTDB2 + 0.00000003400 * TTDB3;
        O  = OE;
        o_ = oE + 0.322555700 * TTDB + 0.0001502600 * TTDB2 + 0.00000047800 * TTDB3;
        lM = lm + 35999.3728519 * TTDB - 0.00000568 * TTDB2 + 0.00000000000 * TTDB3;

    elseif test(1) == 'J'                                            % Jupiter
        aJ = 5.202603191;
        eJ = 0.04849485;
        iJ = 1.303270;
        OJ = 100.464441;
        oJ = 14.331309;
        lm = 34.351484;
        
        a  = aJ + 0.0000001913 * TTDB;
        e  = eJ + 0.0001632440 * TTDB - 0.0000004719 * TTDB2 - 0.00000000197 * TTDB3;
        i_ = iJ - 0.0019872000 * TTDB + 0.0000331800 * TTDB2 + 0.00000009200 * TTDB3;
        O  = OJ + 0.1766828000 * TTDB + 0.0009038700 * TTDB2 - 0.00000703200 * TTDB3;
        o_ = oJ + 0.2155525000 * TTDB + 0.0007225200 * TTDB2 - 0.00000459000 * TTDB3;
        lM = lm + 3034.9056746 * TTDB - 0.0000850100 * TTDB2 + 0.00000000400 * TTDB3;
    end

    M  = lM - o_;                                                     % Classical Elements
    w = o_ - O;                                                       % (page 286.)
    
    E = keplerElliptical( M,  e );
    
    sinv = (sin(E) * sqrt(1.0 - e * e)) / (1.0 - e * cos(E));         % Eccentric Anomaly to 
    cosv = (cos(E) - e) / (1.0 - e * cos(E));                         % True Anomaly.  
    v = atan2(sinv, cosv);                                            % 
    if (v < 0)                                                        % 
     v = v + 2.0 * pi;                                                % 
    end                                                               %
    
    % disp(v);
    % disp(rad2deg(v));
    
    p = a * (1 - e*e);
    
    [r_, v_] = UNIVERSE.randV( p, e, i_, O, w, rad2deg(v) );
    v_ = v_/SUN.TU;
   
end

function E1 = keplerElliptical( M_,  e )
%-------------------------------------------------------------------------------------------------
%
%
   M = deg2rad(M_);

   if     ( (-pi < M) && (M < 0) ) || ( M > +pi )
    E0 = M - e;
   else
    E0 = M + e;
   end

   diff = 1.0;

   while diff > 10e-8
      E1 = E0 + (M - E0 + e * sin(E0)) ./ (1.0 - e * cos(E0));
      diff = abs( E1 - E0 );
      E0 = E1;
      % disp(rad2deg(E1));
   end

   if (E1 < 0)
      E1 = E1 + 2 * pi;
   end

end