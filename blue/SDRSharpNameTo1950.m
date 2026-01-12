function ts = SDRSharpNameTo1950(fileName)
%
%
  fileNameSplit = strsplit(fileName, '.');
  prefix = char(fileNameSplit(1));
  whogi = strsplit(prefix,'_');
  yyyymmdd = char(whogi(2));
  yyyy = str2double(yyyymmdd(1:4));
  mm = str2double(yyyymmdd(5:6));
  dd = str2double(yyyymmdd(7:8));
  hhmnss   = char(whogi(3));
  hh = str2double(hhmnss(1:2));
  mn = str2double(hhmnss(3:4));
  ss = str2double(hhmnss(5:6));
  ts = EARTH.calendarTo1950Seconds(yyyy, mm, dd, hh, mn, ss);
end