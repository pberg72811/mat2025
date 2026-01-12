h5create('myfile.h5','/DS3',[Inf 8],'ChunkSize',[8 8]);

data = randn(8,8);
ii = 1;
start = [ii  1];
count = [ 8  8];
h5write('myfile.h5','/DS3', data, start, count);

data = randn(8,8);
ii = ii + 8;
start = [ii  1];
count = [ 8  8];
h5write('myfile.h5','/DS3', data, start, count);

h5disp('myfile.h5');