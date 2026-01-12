function calAnal(fileName)

fid = fopen(fileName,"r");
x = fread(fid,512,'int8');
y = 0;
z = 0;
d = 0;
for ii = 1:100,
x = fread(fid,1024*10,'int8');
%%x = x+60.*randn(length(x),1);
t = x.^2; t = t-mean(t);
y = y + abs(fft(t));
t = x.^4;t = t-mean(t);
z = z + abs(fft(t));
a = x(1:length(x)-5);
b = x(6:length(x));
t = a+b;t = t-mean(t);
d = d+abs(fft(t));
end
f=32.5/length(x);
f =f.*( 0:length(x)-1);

figure(1);plot(f,abs(fft(x)))
figure(2);plot(f,y)
figure(3);plot(f,z)
figure(4);axis([0 2]);plot(f,z);axis


%%figure(5);axis([0 5]);iccpsd(d,2048,32.5);axis
%%figure(6);plot(x(1:1024))

fclose(fid)
