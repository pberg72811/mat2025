%%-------------------------------UNCLASSIFIED---------------------------------*/
%% File: convEncodeC7R1_2.m
%% Desc: This function does a convolutional encode of an array of one and zeros.
%%       The constrait length is 7 and the rate is 1/2 (C7R1_2 notation).
%%
%% Hist: When       Who  What
%%       07/13/2001 ptb  Initial Code.
%%----------------------------------------------------------------------------*/
function y = convEncodeC7R1_2(x)

  register = [0 0 0 0 0 0 0];
  g2       = [0 0 1 1 0 1 1];
  g1       = [0 1 1 1 0 0 1];
  n        = length(register);
  nm1      = n-1;
  y        = zeros(1,length(x)*2);

  for ii = 1:length(x)-nm1,
    register = x(ii:ii+nm1);
    a = xor(register,g1);
    b = xor(register,g2);
keyboard
    idex = (ii-1)*2+1;
    jdex = (ii)*2;
    y(idex) = rem(sum(a),2);
    y(jdex) = rem(sum(b),2);
  endfor
  