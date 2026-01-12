% A start up script for MATLAB.
%
git25Dir = getenv("USERPROFILE");
git25Dir = strcat(git25Dir,"\GIT25");
mat25Dir = strcat(git25Dir,"\mat2025");
addpath(mat25Dir);
cd(mat25Dir);


addpath("adsb");
addpath("app");
addpath("dsp");
addpath("earth");
addpath("hdf5");
addpath("iono");
addpath("mex");
addpath("sgp");
addpath("utl");

cd(git25Dir)
