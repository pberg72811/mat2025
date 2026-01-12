function theReport = SGP4Processing(dt, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O  )
    %
    %
    %
    % CONSTANTS;

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
    XNO     =   XNO .* TEMP .* XMNPDA;                               % Mean Anomaly
    XNDT2O  =   XNDT2O .* TEMP;                                      % First Time Derivative.
    XNDD6O  =   XNDD6O .* TEMP ./ XMNPDA;                            % Second Time Derivative.
    
    TSINCE = dt / 60;                                                % Time used is in minutes.
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
    %---------------------------------------------------------------------------------------------
    A = XNO + ((2.0 * XNDT2O) + (3.0 * XNDD6O * TSINCE)) * TSINCE;
    A = AO * power ((XNO / A), TWOTHRD);
    E = E6A;
    if (A > QpO)
      E = 1.0 - QpO / A;
    end%if
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
    %---------------------------------------------------------------------------------------------
    AXNSL = E .* cos (OMGAS);
    AYNSL = E .* sin (OMGAS) - C6 / P;
    XL = mod (XLS - C5 / P .* AXNSL, TWOPI);
    
    % SOLVE KEPLERS EQUATION
    %---------------------------------------------------------------------------------------------
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
      end%if
      
      EO1 = EO1 + TEM5;
    end%while
    
    % SHORT PERIOD PRELIMINARY QUANTITIES
    %---------------------------------------------------------------------------------------------
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
    %---------------------------------------------------------------------------------------------
    SIN2U = (COSU + COSU) * SINU;
    COS2U = 1.0 - 2.0 * SINU * SINU;
    RK = R + D1O / PL * COS2U;
    UK = SU - D2O / PL2 * SIN2U;
    XNODEK = XNODES + D3O * SIN2U / PL2;
    XINCK = XINCL + D4O / PL2 * COS2U;
    
    % ORIENTATION VECTORS
    %-------------------------------------------------------------------------------------------------
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
    %-------------------------------------------------------------------------------------------------
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



 
%    // this->p_ecf = xpp::Model::rotateZ_ (this->p_eci, -this->modelGHA);
%    // this->lla = xpp::EarthModel::xyz2LatLonAlt (this->p_ecf);


% % web https://celestrak.org/NORAD/elements/gp.php?GROUP=active&FORMAT=tle
% % CONSTANTS;
% 
% def1 = [...
%     'TEST 01                                                              ';
%     '1 88888U     1A   80275.98708465  .00073094  13844-3  66816-4 0     8';
%     '2 88888  72.8435 115.9689 0086731  52.6988 110.5714 16.05824518   105'];
% 
% prompt = {'TLE', 'dt'};
% rowcol = [3 80; 1 15];
% dfault{1} = def1;
% dfault{2} = '0';
% 
% ins = inputdlg(prompt, 'Enter Two Line Elements', rowcol, dfault);
% 
% tle00 = ins{1}(1,:);
% tle01 = ins{1}(2,:);
% tle02 = ins{1}(3,:);
% dt    = str2double(ins{2});
% 
% %    000000000111111111122222222223333333333444444444455555555556666666666
% %    123456789012345678901234567890123456789012345678901234567890123456789
% %    TEST 01
% %    1 88888U     1A   80275.98708465  .00073094  13844-3  66816-4 0     8
% %    2 88888  72.8435 115.9689 0086731  52.6988 110.5714 16.05824518   105
% %    CALSPHERE 1
% %    1 00900U 64063C   21186.58096723  .00000233  00000-0  23997-3 0  9997
% %    2 00900  90.1618  34.7667 0027273 349.8868  63.8467 13.73553435823046
% %    000000000111111111122222222223333333333444444444455555555556666666666
% %    123456789012345678901234567890123456789012345678901234567890123456789
% 
% obj.satelliteNumber           = sscanf (tle01(3:7),   "%d" );
% obj.classification            = sscanf (tle01(8),     "%c" );
% obj.internationalDesignator1  = sscanf (tle01(10:11), "%s" );
% obj.internationalDesignator2  = sscanf (tle01(12:14), "%s" );
% obj.internationalDesignator3  = sscanf (tle01(15:17), "%s" );
% obj.epochYear                 = sscanf (tle01(19:20), "%d" );
% obj.epochDay                  = sscanf (tle01(21:32), "%f" );
% obj.ftdMeanMotion             = sscanf (tle01(34:43), "%f" );
% obj.stdMeanMotion             = sscanf (tle01(45:52), "%s" );
% obj.bStar                     = sscanf (tle01(54:61), "%s" );
% 
% tmpstr = obj.stdMeanMotion;      
% xx = strsplit(tmpstr,"-");
% yy = strsplit(tmpstr,"+");
% if     ( length(xx) == 2 )
% obj.stdMeanMotion = str2double("." + xx{1} + "e-" + xx{2});
% elseif ( length( yy)  == 2 )
% obj.stdMeanMotion = str2double("." + yy{1} + "e+" + yy{2});
% end%if
% 
% tmpstr = obj.bStar;
% xx = strsplit(tmpstr,"-");
% yy = strsplit(tmpstr,"+");
% if     ( length( xx ) == 2 )
% obj.bStar = str2double("." + xx{1} + "e-" + xx{2});
% elseif ( length( yy ) == 2 )
% obj.bStar = str2double("." + yy{1} + "e+" + yy{2});
% end%if
% 
% obj.satelliteNumber           = sscanf (tle02(3:7),   "%d" );
% obj.inclination               = sscanf (tle02(9:16),  "%f" );
% obj.rightAscension            = sscanf (tle02(18:25), "%f" );
% obj.eccentricity              = sscanf (tle02(27:33), ".%s" );
% obj.argumentOfPerigee         = sscanf (tle02(35:42), "%f" );
% obj.meanAnomaly               = sscanf (tle02(44:51), "%f" );
% obj.meanMotion                = sscanf (tle02(53:63), "%f" );
% obj.revolutionNumberEpoch     = sscanf (tle02(64:68), "%d" );
% tmpstr = obj.eccentricity;
% obj.eccentricity = str2double( "." + tle02(27:33) );
% 
% XINCL   =   obj.inclination .* deg2rad(1);
% XNO     =   obj.meanMotion;
% XMO     =   obj.meanAnomaly .* deg2rad(1);
% EO      =   obj.eccentricity;
% OMEGAO  =   obj.argumentOfPerigee .* deg2rad(1);
% XNODEO  =   obj.rightAscension .* deg2rad(1);
% XNDT2O  =   obj.ftdMeanMotion;
% XNDD6O  =   obj.stdMeanMotion;

% url = 'https://celestrak.org/NORAD/elements/gp.php?GROUP=active&FORMAT=json';
% this = webread(url);
% for ii = 1:length(this)
%     if this(ii).NORAD_CAT_ID == 25544
%         disp(ii)
%         this_ = this(ii);
%         break;
%     end
% end
% 
% XINCL   =   this_.INCLINATION .* deg2rad(1);
% XNO     =   this_.MEAN_MOTION;
% XMO     =   this_.MEAN_ANOMALY .* deg2rad(1);
% EO      =   this_.ECCENTRICITY;
% OMEGAO  =   this_.ARG_OF_PERICENTER .* deg2rad(1);
% XNODEO  =   this_.RA_OF_ASC_NODE .* deg2rad(1);
% XNDT2O  =   this_.MEAN_MOTION_DOT;
% XNDD6O  =   this_.MEAN_MOTION_DDOT;

% dt      =   0.00;
% XINCL   =   72.843500 .* deg2rad(1);
% XNO     =   16.05824518;
% XMO     =   1.105714000000000e+02 .* deg2rad(1);
% EO      =   0.008673100000000;
% OMEGAO  =   52.6988000000000 .* deg2rad(1);
% XNODEO  =   1.159689000000000e+02 .* deg2rad(1);
% XNDT2O  =   7.309400000000000e-04;
% XNDD6O  =   1.384400000000000e-04;
% 
% theReport = processing(dt, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O  );

%-------------------------------------------------------------------------------------------------
% Minutes     Kilometers                                    Kilometers/sec
% SGP TSINCE  X               Y              Z              XDOT        YDOT        ZDOT
%    0.00     2328.96594238  -5995.21600342  1719.97894287  2.91110113  -0.98164053 -7.09049922
%  360.00     2456.00610352  -6071.94232177  1222.95977784  2.67852119  -0.44705850 -7.22800565
%  720.00     2567.39477539  -6112.49725342   713.97710419  2.43952477   0.09884824 -7.31889641
% 1080.00     2663.03179932  -6115.37414551   195.73919105  2.19531813   0.65333930 -7.36169147
% 1440.00     2742.85470581  -6079.13580322  -328.86091614  1.94707947   1.21346101 -7.35499924
