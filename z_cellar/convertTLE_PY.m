function [EPS, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O] = convertTLE_PY(tle01, tle02)
%
% Convert Two Line Element to orbital parameters.
%
    tmp = py.xpy.SGP.convertTLE(tle01, tle02);
    EPS    = double( tmp(1) );
    XINCL  = double( tmp(2) );
    XNO    = double( tmp(3) );
    XMO    = double( tmp(4) );
    EO     = double( tmp(5) );
    OMEGAO = double( tmp(6) );
    XNODEO = double( tmp(7) );
    XNDT2O = double( tmp(8) );
    XNDD6O = double( tmp(9) );
end