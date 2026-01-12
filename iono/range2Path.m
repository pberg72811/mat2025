%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: range2Path.m
%
% Dscr: Range to path calculation.
%
% Hist: Who   When         What
%       ptb   03/01/2018   From Appendix F.
%------------------------------------------UNCLASSIFIED-------------------------------------------
function [Rr, el] = range2Path( gr, vih )

global Dtxrx;

% Re = CONSTANT.Re;
Re = 6378137;

theta = gr./Re;
C = theta./2;

a = Re;
b = Re + vih;

eq1 = a.^2 + b.^2 - 2.*a.*b.*cos(C);
c = sqrt(eq1);
Rr = 2.*c;

eq2 = sin(C)./c;
B = asin(b.*eq2);

if(B<pi/2)
  B = pi - B;
end

A = asin(a.*eq2);

el  = B - pi/2;


end
