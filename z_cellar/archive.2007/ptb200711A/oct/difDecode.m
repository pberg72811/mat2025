%%-------------------------------UNCLASSIFIED---------------------------------*/
%% File: difDeccode.m
%% Desc: This function does a differential decode of an array of one and zeros.
%%       The equation for this function is:
%%                   y[n] = x[n] xor y[n-1];
%%
%% Hist: When       Who  What
%%       07/13/2001 ptb  Initial Code.
%%----------------------------------------------------------------------------*/
function y = difEncode(x)

y = ones(size(x));

for ii = 2:length(x),
    y(ii) = xor(x(ii),x(ii-1));
end