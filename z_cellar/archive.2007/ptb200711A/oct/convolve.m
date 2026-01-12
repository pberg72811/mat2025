function z = convolve(c, x)
  
  l = c;
  l = l(1:length(l)-1);
  l = l.*0;
  l = [l x];
  
  cdex = length(c);
  xdex = length(x);
  ldex = length(l);
  z = zeros(1,ldex);
  
  %keyboard
  
  for ii = 1:xdex
    z(ii) = sum( c .* l(ii:ii+cdex-1));
    %keyboard
  endfor
