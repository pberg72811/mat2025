%%-------------------------------UNCLASSIFIED---------------------------------*/
%% File: difEncode.m
%% Desc: This function does a differential encode of an array of one and zeros.
%%       The equation for this function is:
%%                   y[  1] = x[  1] xor 1;
%%                   y[n+1] = x[n+1] xor y[n];
%%
%% Hist: When       Who  What
%%       07/13/2001 ptb  Initial Code.
%%----------------------------------------------------------------------------*/
function y = difEncode(x)

y    = ones(size(x));
y(1) = xor(x(1), 1);

for ii = 2:length(x),
    y(ii) = xor(x(ii),y(ii-1));
end
