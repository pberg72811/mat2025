%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: smithFactor.m
%
% Dscr: Calculate the smith factor.
%
% Hist: Who   When         What
%       ptb   03/01/2018   From Appendix F.
%------------------------------------------UNCLASSIFIED-------------------------------------------
function [k] = smithFactor( gr)

% Re = CONSTANT.Re;
Re = 6378137;
gr = gr ./ 1000;

term1 = 0.9966;

term2 = 0.0731.*(gr/4000);

term3 = 0.1148.*(gr/4000.0).*(gr/4000.0);

term4 = 0.0034 .* 1000.0./(gr + 1000.0);

k = term1 + term2 + term3 + term4;

end
