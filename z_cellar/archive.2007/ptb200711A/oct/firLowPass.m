function h = firLowPass(n,wc)
     N = floor(-n/2):floor(n/2);
     h = sin(2.*pi.*wc.*N)./(pi.*N);    %% sin(pi.*x)/(pi.*x) vs. sin(x)./x ????
     %%h(floor(0.6+n/2)+1)=2*pi*wc;
     %%win = blackman(n);
     %%h = h.*win.';
     %%N = linspace(-2.*pi, 2.*pi, n);
     %%h = sin(2.*pi.*wc.*N)./(pi.*N);
