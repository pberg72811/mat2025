function...
  [azimuth, elevation, range] = ecef_to_spherical( observer, target) 

    % Calculate differences in ECEF coordinates
    dx = target.x - observer.x;
    dy = target.y - observer.y;
    dz = target.z - observer.z;

    % Calculate range (distance)
    range = sqrt(dx*dx + dy*dy + dz*dz);

    % Calculate azimuth (angle from North)
    azimuth = atan2(dy, dx) * 180.0 / pi;
    if (azimuth < 0)
        azimuth = azimuth + 360.0; % Ensure azimuth is in [0, 360)
    end

    % Calculate elevation (angle above horizon)
    horizontal_distance = sqrt(dx*dx + dy*dy);
    elevation = atan2(dz, horizontal_distance) * 180.0 / pi;

end

% void ecef_to_spherical(ECEF observer, ECEF target, Spherical *result) {
%     // Calculate differences in ECEF coordinates
%     double dx = target.x - observer.x;
%     double dy = target.y - observer.y;
%     double dz = target.z - observer.z;
% 
%     // Calculate range (distance)
%     result->range = sqrt(dx*dx + dy*dy + dz*dz);
% 
%     // Calculate azimuth (angle from North)
%     result->azimuth = atan2(dy, dx) * 180.0 / M_PI;
%     if (result->azimuth < 0) {
%         result->azimuth += 360.0; // Ensure azimuth is in [0, 360)
%     }
% 
%     // Calculate elevation (angle above horizon)
%     double horizontal_distance = sqrt(dx*dx + dy*dy);
%     result->elevation = atan2(dz, horizontal_distance) * 180.0 / M_PI;
% }
% 
% int main() {
%     // Example usage
%     ECEF observer = {6378137.0, 0.0, 0.0}; // Earth's radius at equator, 0 lat/lon
%     ECEF target   = {6378137.0, 1000000.0, 500000.0}; // Example target
% 
%     Spherical result;
%     ecef_to_spherical(observer, target, &result);
% 
%     printf("Azimuth: %.2f°, Elevation: %.2f°, Range: %.2f m\n",
%            result.azimuth, result.elevation, result.range);
% 
%     return 0;
% }
