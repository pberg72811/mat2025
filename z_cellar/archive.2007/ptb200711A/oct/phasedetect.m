%--------------------------------UNCLASSIFIED-----------------------------------
% Name: phaseDetect
%
% Dscr: This script will compare the phase offset from a reference signal with 
%       a signal read in from a X-Midas file.  This script is assuming 8 bit
%       data in the X-Midas file. 
%
% Hist: Who   When       What
%       ptb   04/05/02   Initial code copied from Scott Ramsey code.
%--------------------------------UNCLASSIFIED-----------------------------------
sampRate  = 32.5000e6;
reference = 8.12500e6;
blockSize = 1024;
filesize  = 500000000;
N         = floor((filesize-512)/blockSize);
phase     = zeros(1,4);
rcos      = cos(2*pi*reference*(0:(blockSize-1))/sampRate);
rsin      = sin(2*pi*reference*(0:(blockSize-1))/sampRate);

% Open the X-Midas file.  Read in the X-Midas header (512 bytes long).
%-------------------------------------------------------------------------------
fid  = fopen('/home/bergman/lbfilethin.tmp','rb');
temp = fread(fid, 512, 'int8');

% Calculate the phase steps between blocks.
%-------------------------------------------------------------------------------
phaseStep = (reference/sampRate)*2*pi*blockSize;

% For each block.  Read in the data.  Take out DC component. Compare phases.
%-------------------------------------------------------------------------------
for ii = 1:N,
  temp = fread(fid, blockSize,'int8');
  temp = temp - mean(temp);
  x = rcos*temp;
  y = rsin*temp;
  phase(ii) = rem(atan2(y,x),2*pi);
  if( rem(N,1024) ==0 ), printf("Block number = %d\n", ii); pause(2);endif
end;

fclose(fid);

%%keyboard
%%phase(ii) = rem(atan2(rsin*temp,rcos*temp)+2*pi+ii*phaseStep,2*pi);
%%phase(ii) = rem(atan2(y,x)+ii*phaseStep,2*pi);


function phaseError = phaseDetect(input, reference, sampRate, blockSize)

%
%-------------------------------------------------------------------------------
N = floor(length(input)/blockSize);

% Calculate the phase steps between blocks.
%-------------------------------------------------------------------------------
phaseStep = (reference/sampRate)*2*pi*blockSize;

% For each block.  Read in the data.  Take out DC component. Compare phases.
%-------------------------------------------------------------------------------
for ii = 1:N,
  strt = ((blockSize*(ii-1))+1);
  stop = blockSize*ii;
  temp = input(strt:stop);
  temp = temp - mean(temp);
  x = rcos*temp;
  y = rsin*temp;
  phase(ii) = rem(atan2(y,x),2*pi);
  if( rem(N,1024) ==0 ), printf("Block number = %d\n", ii);endif
end;
