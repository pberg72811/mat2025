% 
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:105]:FOUND POSITION.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:106]:DF = 11.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:107]:ICAO = ac43f9.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:108]:TC = b.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:109]:ALT = 116.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:110]:T = 0.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:111]:F = 0.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:112]:LAT_CPR = 14c0e.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:113]:LON_CPR = 98e5.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:119]:NZ = 15.000000.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:120]:LAT_CPR = 0.648544.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:121]:LON_CPR = 0.298622.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:122]:dLATevn = 6.000000.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:123]:dLONodd = 6.101695.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:124]:
% 
% 
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:105]:FOUND POSITION.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:106]:DF = 11.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:107]:ICAO = ac43f9.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:108]:TC = b.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:109]:ALT = 115.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:110]:T = 0.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:111]:F = 1.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:112]:LAT_CPR = 11341.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:113]:LON_CPR = 10feb.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:119]:NZ = 15.000000.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:120]:LAT_CPR = 0.537605.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:121]:LON_CPR = 0.531090.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:122]:dLATevn = 6.000000.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:123]:dLONodd = 6.101695.
% **MESSAGE**:2018:02:19::23:50:11:[xppADSB.hh:124]:


% NZ is set to 15 (1.3.2.1)
global NZ;
NZ = 15;

dle = 6.000000;
dlo = 6.101695;

latcpr0 = 0.648544;
latcpr1 = 0.537605;

j = floor(59*latcpr0 - 60*latcpr1 + .5);

Lat0 = dle * (mod(j,60)+latcpr0);
Lat1 = dlo * (mod(j,59)+latcpr1);


NL = numberOfLongitudeZones(Lat0);

% t1 = 1-cos(pi/2*NZ);
% t2 = cos(Lat0*pi/180).*cos(Lat0*pi/180);
% t3 = acos(1-(t1/t2));
% NL = floor(2*pi/t3);
NI = max(NL,1);

dLon = 360/NL;

loncpr0 = 0.298622;
loncpr1 = 0.531090;


m = floor(loncpr0*(NL-1)-loncpr1*(NL)+.5);

Lon = dLon * (mod(m,NI)+loncpr0);

if(Lon > 180)
  Lon = Lon-360
end

fprintf('%f, %f\n',Lat0, Lon);


function nl = numberOfLongitudeZones(lat)
global NZ
t1 = 1-cos(pi/2*NZ);
t2 = cos(lat*pi/180).*cos(lat*pi/180);
t3 = acos(1-(t1/t2));
nl = floor(2*pi/t3);
end
