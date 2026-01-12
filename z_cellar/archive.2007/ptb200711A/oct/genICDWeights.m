%--------------------------------UNCLASSIFIED-----------------------------------
% genICDWeights
%
%-------------------------------------------------------------------------------
function genICDWeights(theta, phi, fileName);

fid = fopen(fileName,"w");

% Calculate the weights.
%-------------------------------------------------------------------------------
phaseDelay = tgbfArraySim(theta, phi, 0, 0, 0).';

w = fix(exp(-j*phaseDelay)*1024);
keyboard

fprintf(fid, "%08x\n", real(w(1)) );
fprintf(fid, "%08x\n", real(w(2)) );
fprintf(fid, "%08x\n", real(w(3)) );
fprintf(fid, "%08x\n", real(w(4)) );
fprintf(fid, "%08x\n", real(w(5)) );
fprintf(fid, "%08x\n", real(w(6)) );
fprintf(fid, "%08x\n", imag(w(1)) );
fprintf(fid, "%08x\n", imag(w(2)) );
fprintf(fid, "%08x\n", imag(w(3)) );
fprintf(fid, "%08x\n", imag(w(4)) );
fprintf(fid, "%08x\n", imag(w(5)) );
fprintf(fid, "%08x\n", imag(w(6)) );

fprintf(fid, "%08x\n", real(w( 7)) );
fprintf(fid, "%08x\n", real(w( 8)) );
fprintf(fid, "%08x\n", real(w( 9)) );
fprintf(fid, "%08x\n", real(w(10)) );
fprintf(fid, "%08x\n", real(w(11)) );
fprintf(fid, "%08x\n", real(w(12)) );
fprintf(fid, "%08x\n", imag(w( 7)) );
fprintf(fid, "%08x\n", imag(w( 8)) );
fprintf(fid, "%08x\n", imag(w( 9)) );
fprintf(fid, "%08x\n", imag(w(10)) );
fprintf(fid, "%08x\n", imag(w(11)) );
fprintf(fid, "%08x\n", imag(w(12)) );

fprintf(fid, "%08x\n", real(w(13)) );
fprintf(fid, "%08x\n", real(w(14)) );
fprintf(fid, "%08x\n", real(w(15)) );
fprintf(fid, "%08x\n", real(w(16)) );
fprintf(fid, "%08x\n", real(w(17)) );
fprintf(fid, "%08x\n", real(w(18)) );
fprintf(fid, "%08x\n", imag(w(13)) );
fprintf(fid, "%08x\n", imag(w(14)) );
fprintf(fid, "%08x\n", imag(w(15)) );
fprintf(fid, "%08x\n", imag(w(16)) );
fprintf(fid, "%08x\n", imag(w(17)) );
fprintf(fid, "%08x\n", imag(w(18)) );

fprintf(fid, "%08x\n", real(w(19)) );
fprintf(fid, "%08x\n", real(w(20)) );
fprintf(fid, "%08x\n", real(w(21)) );
fprintf(fid, "%08x\n", real(w(22)) );
fprintf(fid, "%08x\n", real(w(23)) );
fprintf(fid, "%08x\n", real(w(24)) );
fprintf(fid, "%08x\n", imag(w(19)) );
fprintf(fid, "%08x\n", imag(w(20)) );
fprintf(fid, "%08x\n", imag(w(21)) );
fprintf(fid, "%08x\n", imag(w(22)) );
fprintf(fid, "%08x\n", imag(w(23)) );
fprintf(fid, "%08x\n", imag(w(24)) );

fprintf(fid, "%08x\n", real(w(25)) );
fprintf(fid, "%08x\n", real(w(26)) );
fprintf(fid, "%08x\n", real(w(27)) );
fprintf(fid, "%08x\n", real(w(28)) );
fprintf(fid, "%08x\n", real(w(29)) );
fprintf(fid, "%08x\n", real(w(30)) );
fprintf(fid, "%08x\n", imag(w(25)) );
fprintf(fid, "%08x\n", imag(w(26)) );
fprintf(fid, "%08x\n", imag(w(27)) );
fprintf(fid, "%08x\n", imag(w(28)) );
fprintf(fid, "%08x\n", imag(w(29)) );
fprintf(fid, "%08x\n", imag(w(30)) );


%--------------------------------UNCLASSIFIED-----------------------------------
