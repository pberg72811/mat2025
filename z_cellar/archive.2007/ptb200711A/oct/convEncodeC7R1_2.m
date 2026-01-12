%%-------------------------------UNCLASSIFIED---------------------------------*/
%% File: convEncodeC7R1_2.m
%% Desc: This function does a convolutional encode of an array of one and zeros.
%%       The constrait length is 7 and the rate is 1/2 (C7R1_2 notation).
%%           ----+-+---+-+-----|>o--->G2
%%           |   | |   | |
%%           - - - - - - -
%% INPUT -->|0|1|2|3|4|5|6|             o-->S1
%%           - - - - - - -             /
%%           | | | |     |            /
%%           --+-+-+-----+------------>G1
%%
%% Hist: When       Who  What
%%       07/13/2001 ptb  Initial Code.
%%----------------------------------------------------------------------------*/
function y = convEncodeC7R1_2(x)

register = [0 0 0 0 0 0 0];
n        = length(register);
y        = zeros(1,length(x)*2);

for ii = 1:length(x),
    for jj = n:-1:2,
        register(jj) = register(jj-1);
    end
    register(1) = x(ii);
    a = register(1)+register(2)+register(3)+register(4)+register(7);
    b = register(1)+register(3)+register(4)+register(6)+register(7);
    idex = ii*2-1;
    jdex = ii*2;
    y(idex) = rem(a,2);
    y(jdex) = rem(b,2);
    y(jdex) = ~y(jdex);
end
