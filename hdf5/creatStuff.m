close all
clear all

dataDir = getenv("USERPROFILE");
dataDir = strcat(dataDir,"\GIT25\ZDATA00");
h5File = strcat(dataDir,"\codar20250909.h5");
if isfile(h5File)
    delete(h5File);
end

noise = randn(16, 2, 3);

h5create(h5File,"/NOISE_DATA",[16 2 inf], ChunkSize=[16 2 1]);
h5write(h5File,"/NOISE_DATA", noise);

% Prepare data in a MATLAB structure
data.fs    = single(32000);
data.bw    = int32(2000);
data.sweep = 5000;

% OPEN HDF5 file
fid = H5F.open(h5File, 'H5F_ACC_RDWR',  'H5P_DEFAULT');

% Create a compound DATATYPE for a ROP
compondSize = 0;
compondSize = compondSize + H5T.get_size('H5T_NATIVE_FLOAT');
compondSize = compondSize + H5T.get_size('H5T_NATIVE_INT');
compondSize = compondSize + H5T.get_size('H5T_NATIVE_DOUBLE');

tid = H5T.create('H5T_COMPOUND', compondSize);

% Insert fields
H5T.insert(tid, 'FS',    0, 'H5T_NATIVE_FLOAT');
H5T.insert(tid, 'BW',    4, 'H5T_NATIVE_INT');
H5T.insert(tid, 'SWEEP', 8, 'H5T_NATIVE_DOUBLE');

% Create DATASPACE
sid = H5S.create('H5S_SCALAR');

% Create DATASET
did = H5D.create(fid, '/ROP', tid, sid, 'H5P_DEFAULT');

% Write data
% H5D.write(dset, tid, space,          'H5S_ALL', 'H5S_ALL', 'H5P_DEFAULT', data);
% H5D.write(dset, tid, 'H5ML_DEFAULT', 'H5S_ALL', 'H5S_ALL', 'H5P_DEFAULT', data);
H5D.write( did, 'H5ML_DEFAULT', 'H5S_ALL', 'H5S_ALL', 'H5P_DEFAULT', data(1) );

% Close resources
H5D.close(did);
H5S.close(sid);
H5T.close(tid);
H5F.close(fid);

moreNoise = randn(16, 2, 3);

h5write(h5File,"/NOISE_DATA", moreNoise,'WriteMode', 'append');