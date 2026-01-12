%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: qvih2vih.m
%
% Dscr: This function converts iono-gram quasi vertical height to iono-gram vertical height
%
% Hist: Who   When         What
%       ptb   03/01/2018   From Appendix F.
%------------------------------------------UNCLASSIFIED-------------------------------------------
function [vih] = qvih2vih( qvih )

global Dtxrx;

vih = sqrt(qvih.*(qvih-Dtxrx));

end
