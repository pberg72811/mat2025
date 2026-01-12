% A start up script for MATLAB.
%
git25Dir = getenv("USERPROFILE");
git25Dir = strcat(git25Dir,"\GIT25");
cd(git25Dir);

dirList = dir("*2025*");

for ii = 1:length(dirList)
    aFolder =  strcat(git25Dir, '\', dirList(ii).name );
    if isfolder(aFolder), addpath(aFolder); end

    aFolder =  strcat(git25Dir, '\', dirList(ii).name, '\mat' );
    if isfolder(aFolder), addpath(aFolder); end

    aFolder =  strcat(git25Dir, '\', dirList(ii).name, '\mex' );
    if isfolder(aFolder), addpath(aFolder); end

    aFolder =  strcat(git25Dir, '\', dirList(ii).name, '\mlx' );
    if isfolder(aFolder), addpath(aFolder); end

    aFolder =  strcat(git25Dir, '\', dirList(ii).name, '\res' );
    if isfolder(aFolder), addpath(aFolder); end
end

aFolder =  strcat(git25Dir, '\ZDATA00');
if isfolder(aFolder), addpath(aFolder); end

dispTopOfPathList();

function dispTopOfPathList()
%
% Display the top part of the PATH list.
%
    list = path;
    x = strsplit(list,';')';
    disp("YOUR PATH IS:");
    disp(" ");
    disp( x(1:8) );
    disp("Plus the rest ...");
end


% Python Support:
% In this folder, create virtual environment using "python3 -m venv .venv" and then 
% uncommenting the code lines below.
%-------------------------------------------------------------------------------------------------
% tmpPath = getenv("USERPROFILE");
% pythonVENV = [tmpPath '\GIT25\.venv\Scripts\python.exe'];
% pythonEnvironment = pyenv("Version", pythonVENV);
% insert(py.sys.path, int64(0), curFolder);
% py.importlib.import_module('xpy');


% XPY = py.importlib.import_module('xpy');
% XPY_EARTH = py.importlib.import_module('xpy.EARTH');
% XPY_UNIVERSE = py.importlib.import_module('xpy.UNIVERSE');
% 
% py.importlib.reload(XPY);
% py.importlib.reload(XPY_EARTH);
% py.importlib.reload(XPY_UNIVERSE);
% 
% py.help(XPY);
% py.help(XPY_EARTH.currentJulianSeconds);
% py.help(XPY_EARTH.calendarToJulianDay);
% py.help(XPY_EARTH.ROT3);help 