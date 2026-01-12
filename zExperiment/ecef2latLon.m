x = 6524.834
y = 6862.875
z = 6448.296

rDelSat = sqrt( x*x + y*y );
disp(rDelSat);

sinAlpha = y./rDelSat;
disp(asind(sinAlpha));

tanDelta = z./rDelSat
disp(atand(tanDelta))
