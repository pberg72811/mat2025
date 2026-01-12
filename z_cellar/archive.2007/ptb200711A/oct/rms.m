%RMS function.

function y = rms(x)

y = 0;

N = length(x);

for ii = 1:N
  y = y + x(ii)*x(ii);
endfor

y = y./N;
