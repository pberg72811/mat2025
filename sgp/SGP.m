classdef SGP < handle
%-------------------------------------------------------------------------------------------------
% Simplified General Perturbation model for satellite orbits.
% Class that encapsulates SPACETRACK REPORT NO. 3 Models for Propagation of NORAD Element Sets.
%
    
    properties (Constant)
      JUNK   = 1.9885e30         % Kilograms
    end

    %---------------------------------------------------------------------------------------------
    methods (Static)
    %---------------------------------------------------------------------------------------------

    function theReport = Model(dt, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O)
    %---------------------------------------------------------------------------------------------
    % Simplified General Perturbation model for satellite orbits.
    %

        XMO = deg2rad(XMO);
        XINCL = deg2rad(XINCL);
        OMEGAO = deg2rad(OMEGAO);
        XNODEO = deg2rad(XNODEO);
        
        AE      = +1.000000;
        CK2     = +5.413080E-4;
        % CK4     = +0.62098875E-6;
        E6A     = +1.0000E-6;
        % XJ2     = +1.082616E-3;
        XJ3     = -0.253881E-5;
        % XJ4     = -1.65597E-6;
        XKE     = +0.743669161E-1;
        C1      = CK2 * 1.5;
        C2      = CK2 / 4.0;
        C3      = CK2 / 2.0;
        C4      = XJ3 * (AE * AE * AE) / (4.0 * CK2);
        % X3PIO2  = +4.712388980384690;
        % QOMS2T  = +1.88027916e-9;
        XMNPDA  = +1440.0;
        TWOPI   = +2*pi;
        TWOTHRD = +2/3;
        XKMPER  = 6378136.3 / 1000.0; 
        
        TEMP    =   TWOPI ./ XMNPDA ./ XMNPDA;
        XNO     =   XNO .* TEMP .* XMNPDA;                           % Mean Anomaly
        XNDT2O  =   XNDT2O .* TEMP;                                  % First Time Derivative.
        XNDD6O  =   XNDD6O .* TEMP ./ XMNPDA;                        % Second Time Derivative.
        
        TSINCE = dt / 60;                                            % Time used is in minutes.
        COSIO = cos (XINCL);
        SINIO = sin (XINCL);
        A1 = power ((XKE / XNO), TWOTHRD);
        % Replace this equations with the lines below:
        % RFLT64 D1 = C1 / A1 / A1 * (3.0 * COSIO * COSIO - 1.0)
        % pow((1.0 - this->EO * this->EO),^1.5);
        TERM1 = C1 ./ A1 ./ A1 .* (3.0 .* COSIO .* COSIO - 1.0);
        TERM2 = power ((1.0 - EO * EO), 1.5);
        D1 = TERM1 / TERM2;
        AO = A1 .* (1.0 - 1.0 ./ 3.0 .* D1 - D1 .* D1 - 134.0 ./ 81.0 .* D1 .* D1 .* D1);
        PO = AO * (1.0 - EO * EO);
        QpO = AO * (1.0 - EO);
        XLO = XMO + OMEGAO + XNODEO;
        D1O = C3 * SINIO * SINIO;
        D2O = C2 * (7. * COSIO * COSIO - 1.);
        D3O = C1 * COSIO;
        D4O = D3O * SINIO;
        PO2NO = XNO ./ (PO .* PO);
        OMGDT = C1 .* PO2NO .* (5 .* COSIO .* COSIO - 1);
        XNODOT = -2. .* D3O .* PO2NO;
        C5 = .5 .* C4 .* SINIO .* (3 + 5 .* COSIO) ./ (1 + COSIO);
        C6 = C4 .* SINIO;
        
        % UPDATE FOR SECULAR GRAVITY AND ATMOSPHERIC DRAG
        %-----------------------------------------------------------------------------------------
        A = XNO + ((2.0 * XNDT2O) + (3.0 * XNDD6O * TSINCE)) * TSINCE;
        A = AO * power ((XNO / A), TWOTHRD);
        E = E6A;
        if (A > QpO)
          E = 1.0 - QpO / A;
        end
        P = A .* (1 - E .* E);
        XNODES = XNODEO + XNODOT .* TSINCE;
        OMGAS = OMEGAO + OMGDT .* TSINCE;
        % Replace this equations with the lines below:
        % XLS = fmod(XLO + (XNO + OMGDT + XNODOT +
        % (XNDT2O + XNDD6O * TSINCE) * TSINCE) * TSINCE, TWOPI);
        TERM1 = (XNDT2O + XNDD6O .* TSINCE) .* TSINCE;
        TERM2 = (XNO + OMGDT + XNODOT + TERM1) .* TSINCE;
        TERM3 = XLO + TERM2;
        XLS = mod (TERM3, TWOPI);
        
        % LONG PERIOD PERIODICS
        %-----------------------------------------------------------------------------------------
        AXNSL = E .* cos (OMGAS);
        AYNSL = E .* sin (OMGAS) - C6 / P;
        XL = mod (XLS - C5 / P .* AXNSL, TWOPI);
        
        % SOLVE KEPLERS EQUATION
        %-----------------------------------------------------------------------------------------
        U = mod (XL - XNODES, TWOPI);
        ITEM3 = 0;
        EO1 = U;
        TEM5 = 1.0;
        
        while ((abs (TEM5) >= E6A) || (ITEM3 < 10.0))
        
          SINEO1 = sin (EO1);
          COSEO1 = cos (EO1);
          ITEM3 = ITEM3 + 1.0;
          TEM5 = 1.0 - COSEO1 .* AXNSL - SINEO1 .* AYNSL;
          TEM5 = (U - AYNSL .* COSEO1 + AXNSL .* SINEO1 - EO1) ./ TEM5;
          TEM2 = abs (TEM5);
          if (TEM2 > 1.0)
            TEM5 = TEM2 ./ TEM5;
          end
          
          EO1 = EO1 + TEM5;
        end
        
        % SHORT PERIOD PRELIMINARY QUANTITIES
        %-----------------------------------------------------------------------------------------
        ECOSE = AXNSL * COSEO1 + AYNSL * SINEO1;
        ESINE = AXNSL * SINEO1 - AYNSL * COSEO1;
        EL2 = AXNSL * AXNSL + AYNSL * AYNSL;
        PL = A * (1.0 - EL2);
        PL2 = PL * PL;
        R = A * (1.0 - ECOSE);
        RDOT = XKE * sqrt (A) / R * ESINE;
        RVDOT = XKE * sqrt (PL) / R;
        TEMP = ESINE / (1.0 + sqrt (1.0 - EL2));
        SINU = A / R * (SINEO1 - AYNSL - AXNSL * TEMP);
        COSU = A / R * (COSEO1 - AXNSL + AYNSL * TEMP);
        SU = atan2 (SINU, COSU);
        
        % UPDATE FOR SHORT PERIODICS
        %-----------------------------------------------------------------------------------------
        SIN2U = (COSU + COSU) * SINU;
        COS2U = 1.0 - 2.0 * SINU * SINU;
        RK = R + D1O / PL * COS2U;
        UK = SU - D2O / PL2 * SIN2U;
        XNODEK = XNODES + D3O * SIN2U / PL2;
        XINCK = XINCL + D4O / PL2 * COS2U;
        
        % ORIENTATION VECTORS
        %-----------------------------------------------------------------------------------------
        SINUK = sin (UK);
        COSUK = cos (UK);
        SINNOK = sin (XNODEK);
        COSNOK = cos (XNODEK);
        SINIK = sin (XINCK);
        COSIK = cos (XINCK);
        XMX = -SINNOK * COSIK;
        XMY = COSNOK * COSIK;
        UX = XMX * SINUK + COSNOK * COSUK;
        UY = XMY * SINUK + SINNOK * COSUK;
        UZ = SINIK * SINUK;
        VX = XMX * COSUK - COSNOK * SINUK;
        VY = XMY * COSUK - SINNOK * SINUK;
        VZ = SINIK * COSUK;
        %
        %//    DB.MESSAGE(__LINE__, "SINUK   is %18.9lf\n", SINUK);
        %//    DB.MESSAGE(__LINE__, "COSUK   is %18.9lf\n", COSUK);
        %//    DB.MESSAGE(__LINE__, "SINNOK  is %18.9lf\n", SINNOK);
        %//    DB.MESSAGE(__LINE__, "COSNOK  is %18.9lf\n", COSNOK);
        %//    DB.MESSAGE(__LINE__, "SINIK   is %18.9lf\n", SINIK);
        %//    DB.MESSAGE(__LINE__, "COSIK   is %18.9lf\n", COSIK);
        %//    DB.MESSAGE(__LINE__, "XMX     is %18.9lf\n", XMX);
        %//    DB.MESSAGE(__LINE__, "XMY     is %18.9lf\n", XMY);
        %//    DB.MESSAGE(__LINE__, "UX      is %18.9lf\n", UX);
        %//    DB.MESSAGE(__LINE__, "UY      is %18.9lf\n", UY);
        %//    DB.MESSAGE(__LINE__, "UZ      is %18.9lf\n", UZ);
        %
        %// POSITION AND VELOCITY
        %-----------------------------------------------------------------------------------------
        px = RK * UX;
        py = RK * UY;
        pz = RK * UZ;
        
        vx = RDOT * UX;
        vy = RDOT * UY;
        vz = RDOT * UZ;
        
        vx = RVDOT * VX + vx;
        vy = RVDOT * VY + vy;
        vz = RVDOT * VZ + vz;
        
        px = 1000.0 .* px .* XKMPER ./ AE;                               %% * 1000 for Meters.
        py = 1000.0 .* py .* XKMPER ./ AE;                               %% * 1000 for Meters.
        pz = 1000.0 .* pz .* XKMPER ./ AE;                               %% * 1000 for Meters.
        vx = 1000.0 .* vx .* XKMPER ./ AE .* XMNPDA ./ 86400.0;          %% * 1000 for Meters.
        vy = 1000.0 .* vy .* XKMPER ./ AE .* XMNPDA ./ 86400.0;          %% * 1000 for Meters.
        vz = 1000.0 .* vz .* XKMPER ./ AE .* XMNPDA ./ 86400.0;          %% * 1000 for Meters.
        
        theReport = table(px, py, pz, vx, vy, vz);
    end

    function [EPS, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O] = convertTLE(tle1, tle2)
    %---------------------------------------------------------------------------------------------
    % Convert Two Line Element to orbital parameters.
    %
        tle1 = strip(tle1);
        tle2 = strip(tle2);
        
        crdNo = tle1(1);                    %#ok<NASGU>
        space = tle1(2);                    %#ok<NASGU>
        satNo = tle1(3:7);                  %#ok<NASGU>
        class = tle1(8);                    %#ok<NASGU>
        space = tle1(9);                    %#ok<NASGU>
        year_ = tle1(10:11);                %#ok<NASGU>
        launc = tle1(12:14);                %#ok<NASGU>
        piece = tle1(15:17);                %#ok<NASGU>
        space = tle1(18);                   %#ok<NASGU>
        epoch = tle1(19:32);
        space = tle1(33);                   %#ok<NASGU>
        XNDT2O = str2double(tle1(34:43));
        space = tle1(44);                   %#ok<NASGU>
        XNDD6O = tle1(45:52);
        space = tle1(53);                   %#ok<NASGU>
        BSTAR = tle1(54:61);
        space = tle1(62);                   %#ok<NASGU>
        eph_t = tle1(63);                   %#ok<NASGU>
        space = tle1(64);                   %#ok<NASGU>
        next_ = tle1(65:68);                %#ok<NASGU>
        chksm = tle1(69);                   %#ok<NASGU>
    
        epochYear = str2double(epoch(1:2));
        epochDay  = str2double(epoch(3:end));
        EPS = SGP.norad2Seconds(epochYear, epochDay);
        
        XNDD6O = str2double(SGP.bStarNumberConversion(XNDD6O));
        BSTAR = str2double(SGP.bStarNumberConversion(BSTAR)); %#ok<NASGU>
        
        
        crdNo = tle2(1);                    %#ok<NASGU>
        space = tle2(2);                    %#ok<NASGU>
        satNo = tle2(3:7);                  %#ok<NASGU>
        space = tle2(8);                    %#ok<NASGU>
        XINCL = str2double(tle2(9:16));
        space = tle2(17);                   %#ok<NASGU>
        XNODEO = str2double(tle2(18:25));
        space = tle2(26);                   %#ok<NASGU>
        EO = str2double(['.' tle2(27:33)]);
        space = tle2(34);                   %#ok<NASGU>
        OMEGAO = str2double(tle2(35:42));
        space = tle2(43);                   %#ok<NASGU>
        XMO = str2double(tle2(44:51));
        space = tle2(52);                   %#ok<NASGU>
        XNO = str2double(tle2(53:63));
        eporv = tle2(64:68);                %#ok<NASGU>
        chksm = tle1(69);                   %#ok<NASGU>
    
    end

    function bStarStr = bStarNumberConversion(bStar)
    %---------------------------------------------------------------------------------------------
    % Goes for XNDD6O also
    %
        if(bStar(1) == '-')     % '-00000+0'
          bStar(1) = ' ';
          unity = -1;
        elseif(bStar(1) == '+') % '+00000+0' Should never happen ' 00000+0'
          bStar(1) = ' ';
          unity = +1;
        else
          unity = +1;
        end
        
        bStarStr = ['0.' strip(bStar) ];
        bStarStr = strrep(bStarStr,'-','e-');
        bStarStr = strrep(bStarStr,'+','e+');
        
        if unity < 0
          bStarStr = ['-' bStarStr];
        end
    end
    
    function JS = norad2Seconds( yy, day )
    %---------------------------------------------------------------------------------------------
    % Return epoch 1970 seconds from  NORAD year/day date.
    %
        if yy < 50
          yyyy = yy + 2000;
        else
          yyyy = yy + 1900;
        end
        
        JD = EARTH.calendarToJulianDay(yyyy, 1, 1, 0, 0, 0);
        JS = ( JD + (day - 1) ) * 86400;
    
    end
    %---------------------------------------------------------------------------------------------
    end
    %---------------------------------------------------------------------------------------------
end


    % function theReport = Model_PY(dt, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O  )
    % %---------------------------------------------------------------------------------------------
    % %
    % %
    %    tmp = py.xpy.SGP.Model( dt, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O );
    %    px = double( tmp(1) );
    %    py_ = double( tmp(2) );
    %    pz = double( tmp(3) );
    %    vx = double( tmp(1) );
    %    vy = double( tmp(2) );
    %    vz = double( tmp(3) );
    %    theReport = table(px, py_, pz, vx, vy, vz);
    % end

    %     function [EPS, XINCL, XNO, XMO, ...
    %           EO, OMEGAO, XNODEO, XNDT2O, XNDD6O] = convertTLE_PY(tle01, tle02)
    % %---------------------------------------------------------------------------------------------
    % % Convert Two Line Element to orbital parameters. ** PYTHON **
    % %
    %     tmp = py.xpy.SGP.convertTLE(tle01, tle02);
    %     EPS    = double( tmp(1) );
    %     XINCL  = double( tmp(2) );
    %     XNO    = double( tmp(3) );
    %     XMO    = double( tmp(4) );
    %     EO     = double( tmp(5) );
    %     OMEGAO = double( tmp(6) );
    %     XNODEO = double( tmp(7) );
    %     XNDT2O = double( tmp(8) );
    %     XNDD6O = double( tmp(9) );
    % end