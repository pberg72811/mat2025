function [lat1,lon1, lat2, lon2] = ohioStateRADARElements()
%
% Create imaginary RADAR elements near Ohio State stadium.
%
  [lat1, lon1, lat2, lon2] = navyRADARElements();

  lat1 = lat1 + 2.443413136634668;
  lat2 = lat2 + 2.443413136634668;
  
  lon1 = lon1 + 5.992341434616776;
  lon2 = lon2 + 5.992341434616776;

end

% Can check placement with the following: 
%
% geoplot(lats, lons, "*b");
% geobasemap streets
% geolimits([40.00702 40.00948],[-83.01982 -83.01496])