N = 512;
y = zeros(1,N);
d = 2*pi*700./8000;
x = sin( (0:N-1).*d );
for kk = 0:N-1;
  for nn = 0:N-1;
    y(kk+1) = y(kk+1) + x(nn+1).*(cos(nn*kk*2*pi/N)+sin(nn*kk*2*pi/N)*j);
  endfor
endfor
