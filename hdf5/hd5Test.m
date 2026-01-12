% myData = ones(100,200,300);
% h5create("myFile.h5","/DRx3data")
% %h5write("myFile.h5","/g1/g2/myDataset",myData)
% h5disp("myFile.h5")

spaceID = H5S.create("H5S_SIMPLE");
dims = [100 200];
h5_dims = fliplr(dims);
maxdims = [100 H5ML.get_constant_value("H5S_UNLIMITED")];
h5_maxdims = fliplr(maxdims);
H5S.set_extent_simple(spaceID,2,h5_dims, h5_maxdims);
H5S.close(spaceID);
