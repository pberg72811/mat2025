x = randn(1,4096);
y = zeros(1,4096);
z = zeros(1,4096);
a = zeros(1,4096./8);
b = zeros(1,4096./8);
c = zeros(1,4096./8);
d = zeros(1,4096./8);

for ii = 1:length(x),
	   y(ii+1) = y(ii)+x(ii);
endfor

%for ii = 1:length(x),
%	   z(ii+1) = z(ii)+y(ii);
%endfor
%
%for ii = 1:length(x),
%	   a(ii+1) = a(ii)+z(ii);
%endfor
%

a = y(1:8:length(y));

for ii = 1:length(a)
     b(ii+1) = b(ii)-a(ii);
endfor

%
%for ii = 1:length(b)
%     c(ii+1) = c(ii)-b(ii);
%endfor
%
%for ii = 1:length(c)
%     d(ii+1) = d(ii)-c(ii);
%endfor
