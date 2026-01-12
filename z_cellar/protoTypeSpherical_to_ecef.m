clearvars

this = lfmSweepClass(32000, 10e3, 100e3);

deltaR = UNIVERSE.C/(2*this.sbw);


[x, y, z] = function ...
  spherical_to_ecef( azimuth, elevation, range, lat_rad, lon_rad, alt_m) 

  % Convert spherical to local ENU (East, North, Up) coordinates
  sin_az = sin(azimuth);
  cos_az = cos(azimuth);
  sin_el = sin(elevation);
  cos_el = cos(elevation);

  x_enu = range * cos_el * sin_az;
  y_enu = range * cos_el * cos_az;
  z_enu = range * sin_el;

  % Convert ENU to ECEF
  sin_lat = sin(lat_rad);
  cos_lat = cos(lat_rad);
  sin_lon = sin(lon_rad);
  cos_lon = cos(lon_rad);

    x = -sin_lon * x_enu - cos_lon * sin_lat * y_enu + cos_lat * cos_lon * z_enu;
    x = x + (alt_m + 6378137.0) * cos_lat * cos_lon; % WGS84 Earth radius + altitude

    y =  cos_lon * x_enu - sin_lon * sin_lat * y_enu + cos_lat * sin_lon * z_enu;
    y = y + (alt_m + 6378137.0) * cos_lat * sin_lon;

    z =  cos_lat * y_enu + sin_lat * z_enu;
    z = z + (alt_m * (1 - 6.69437999014e-3) + 6356752.314245); % WGS84 Earth radius at poles + altitude

end