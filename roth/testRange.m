clearvars
load radarReturn_20251112_081611.mat

sweepSamples = ROP.Fs * ROP.Bw/ROP.Swr;

strt = 300*sweepSamples;
stop = strt + sweepSamples - 1;
ret = radarReturn_(strt:stop);

subplot(311); plot( real(ret) );

lfm = lfmSweepClass(ROP.Fs, ROP.Bw, ROP.Swr);


subplot(312); plot( real(lfm.signal_) );


fftRet = fft(ret);
fftRep = fft(flip(lfm.signal_));

fftMul = fftRet .* conj(fftRep);

matchedFilter = ifft(fftMul);

subplot(313); plot(real(matchedFilter))
hold on;
plot(imag(matchedFilter))
hold off;