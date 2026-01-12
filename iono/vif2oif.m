%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: vif2oif.m
%
% Dscr: Calculate Oblique Ionogram frequencies based on Vertical Ionogram frequencies.
%
% Hist: Who   When         What
%       ptb   03/01/2018   From Appendix F.
%------------------------------------------UNCLASSIFIED-------------------------------------------
function [oif] = vif2oif( vif, vih, rr, gr)

% Re = CONSTANT.Re;
Re = 6378137;

term1 = sin(gr./(4.*Re));

term2 = vih + 2.*Re.*term1.*term1;

term3 = (rr./2)';

k = smithFactor(gr);

OIk = 1;

oif = vif.*k.*OIk.*term3./term2;

oif = oif .* (oif < 35e6);

end
