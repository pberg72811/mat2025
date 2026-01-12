%eneVisible.m

sat = iccSatState("/home/steswd/steswd/dat/theTLE.txt", "TDRS 4")

for ii = 1:1818,

wacName = sprintf("WAC%04d",ii);

stat = iccStatState("/home/steswd/steswd/dat/WACLLA.txt",wacName);

[a,b,g,eo] = uCalcDirCos([sat(4) sat(5) sat(6)], [sat(7) sat(8) sat(9)], [stat(4) stat(5) stat(6)]);

if(!eo),
  printf("%s %+02d %+03d\n",wacName, stat(1), stat(2));
end

end
