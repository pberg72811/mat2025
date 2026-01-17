% A start up script for MATLAB.
%
userDir = getenv("USERPROFILE");                 % DEFINE USER FOLDER.
git_Dir = strcat(userDir,"\GIT25");              % DEFINE GIT FOLDER.
one_Dir = strcat(userDir,"\OneDrive\GIT25");     % DEFINE ONE DRIVE FOLDER.


dataDir = strcat(git_Dir, "\ZDATA00");           % DATA00 directory.
if isfolder(dataDir), addpath(dataDir); end      %

dataDir = strcat(git_Dir, "\ZDATA01");           % DATA01 directory.
if isfolder(dataDir), addpath(dataDir); end      %

dataDir = strcat(one_Dir, "\ZDATA99");           % DATA99 directory.
if isfolder(dataDir), addpath(dataDir); end      %

mat25Dir = strcat(git_Dir,"\mat2025");           % MAT2025 directory.
if isfolder(mat25Dir), addpath(mat25Dir); end    %

addpath("app");
addpath("blue");
addpath("docker");
addpath("dsp");
addpath("hdf5");
addpath("heliocentric");
addpath("iono");
addpath("mex");
addpath("res"); 
addpath("roth"); 
addpath("sgp");
addpath("utl");
addpath("wsl");

dispTopOfPathList();

%-------------------------------------------------------------------------------------------------
function dispTopOfPathList()
%
% Display the top part of the PATH list.
%-------------------------------------------------------------------------------------------------
    list = path;
    x = strsplit(list,';')';
    disp("YOUR PATH IS:");
    disp(" ");
    disp( x(1:16) );
    disp("Plus the rest ...");
end