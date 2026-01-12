x = 3;
y = 2;
z = 2;
a = 5;
nDimensons = 4;

rows = x*y*z*a;
cols = nDimensons;
imgBuffer = zeros(rows,cols);

ii = 1;
for aa = 0:(a-1)
  for zz = 0:(z-1)
    for yy = 0:(y-1)
      for xx = 0:(x-1)
        disp( [aa zz yy xx ] )
        imgBuffer(ii,:) = [aa zz yy xx] * 25;
        ii = ii + 1;
      end
    end
  end
end

image(imgBuffer)