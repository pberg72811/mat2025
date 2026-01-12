global Dtxrx;

Dtxrx=100*1000;

viTestData = [...
  1 201;
  2 211;
  3 221;
  4 241;
  5 271;
  6 311;
  7 361;
  8 431];

qvih = viTestData(:,2)*1000;
qvif = viTestData(:,1)*1e6;

vih = qvih2vih(qvih);
vif = qvif2vif(qvif, qvih, vih);

faxis = linspace(vif(1), vif(end), 20);
vih_n = interp1(vif, vih, faxis);

Rr = zeros(20,55);
el = zeros(20,55);
OIf = zeros(20,55);

ii = 1;
for grdex = 100000:100000:5500000,
  [Rr(:,ii), el(:,ii)] = range2Path(grdex, vih_n);
  OIf(:,ii) = vif2oif(faxis, vih_n, Rr(:,ii), grdex);
  ii = ii + 1;
end

  

