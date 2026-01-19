function phiGrn = jd2PhiGrn(julianDate)
%------------------------------------------UNCLASSIFIED-------------------------------------------
% Takes Julian Day and returns Greenwich Hour Angle in radians.
% Fundamentals of Astrodynamics and Applications (2nd Ed), David A. Vallado, page 212.
% 
  t1 = 0.7790572732640;
  t2 = 1.00273781191135448;
  t3 = julianDate - 2451545.0;
  phiGrn = 2 * pi * ( t1 + (t2 * t3) );
  phiGrn = mod(phiGrn, 2*pi);
end