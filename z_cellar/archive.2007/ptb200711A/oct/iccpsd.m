function y = iccpsd(x,fftSize,fs);
%% Power spectral density plot.
%% Created for use in Matlab and Octave.
%% y = iccpsd(x,fftSize,fs)
%% 120502 axis was off by one bin.  Was 1:(fftSize./2) now 0:(fftSize./2)-1
%%-------------------------------------------------------------------------------

% Calculate step size base on input data.
%-------------------------------------------------------------------------------
fftStep = length(x)./fftSize;

% Size the vector that is going to hold the magnitude data.
% Create the hanning window also.
%-------------------------------------------------------------------------------
[a,b] = size(x);
if(a>b)
  y = zeros(fftSize,1);
  W = hanning(fftSize);
else
  y = zeros(1,fftSize);
  W = hanning(fftSize).';
end

% Sum fftStep number of magnitude plots.
%-------------------------------------------------------------------------------
for ii = 0:(fftStep-1)
  strt = fftSize*ii+1;
  stop = fftSize*(ii+1);
  xw = x(strt:stop).*W;
  y = y + abs(fft(xw))./fftSize;
end

% Normalize for the number of fftSteps and take 10 log10 of magnitude.
%-------------------------------------------------------------------------------
y = y./fftStep;
y = 10.*log10(y);

% Check to see if input is real and scale the xaxis accordingly.
%-------------------------------------------------------------------------------
if(!is_complex(x))
  y = y(1:fftSize./2);
  y = y/(fftSize.*2);
  xaxis = (0:(fftSize./2)-1).*fs./fftSize;
else
  y = y/(fftSize);
  xaxis = (0:(fftSize./1)-1).*fs./fftSize;
end

% Plot, set grid, set labels and title.
%-------------------------------------------------------------------------------
plot(xaxis,y);
grid;
xlabel('Frequency');
ylabel('Power Spectrum Magnitude (dB)');
title('iccpsd');
replot;
