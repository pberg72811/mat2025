%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: qvif2vif.m
%
% Dscr: This function converts iono-gram quasi vertical frequency to iono-gram vertical frequency.
%
% Hist: Who   When         What
%       ptb   03/01/2018   From Appendix F.
%------------------------------------------UNCLASSIFIED-------------------------------------------
function [vif] = qvif2vif( qvif, qvih, vih )

global Dtxrx;

vif = qvif .* (2.*vih)./(2.*qvih + Dtxrx);

end
