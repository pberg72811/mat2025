function resultTable = compareThem(theReport, px, py, pz, vx, vy, vz)
%
%
%
  varNames = [ "px",  "py", "pz", "vx", "vy", "vz"];

  theAnswer = table(px, py, pz, vx, vy, vz, 'VariableNames',varNames );

  row1 = theReport;
  row2 = theAnswer .* 1000;
  row3 = theReport - (theAnswer.*1000);
  
  resultTable  = [
    row1;
    row2;
    row3];

end