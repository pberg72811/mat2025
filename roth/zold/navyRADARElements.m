function [lat1,lon1, lat2, lon2] = navyRADARElements()
%
% Create RADAR elements near Ohio State stadium.
%

  lat1 = linspace( +37.56471566761531, +37.56504156214795, 16);
  lon1 = linspace( -77.02492387826882, -77.02315533241601, 16);
  
  lat2 = linspace( +37.564472026873595, +37.56463406975547, 16);
  lon2 = linspace( -77.026233994593280, -77.02535206202278, 16);

end

% Can check placement with the following: 
%
% geoplot([lat1 lat2], [lon1 lon2],"*b")
% geobasemap streets
% geolimits( [37.56346 37.56676], [-77.02781 -77.02151] );