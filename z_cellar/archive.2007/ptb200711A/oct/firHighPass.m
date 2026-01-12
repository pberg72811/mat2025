function h = firHighPass(n,wc)
     N = floor(-n/2):floor(n/2);
     h = sin(2.*pi.*wc.*N)./(N);    %% sin(pi.*x)/(pi.*x) vs. sin(x)./x ????
     h = -h;
     h(floor(0.6+n/2)+1)=2*pi*wc;

     %%%N = linspace(-2.*pi, 2.*pi, n);
     %%%h = sin(2.*pi.*wc.*N)./(pi.*N);
     %%%h = -h;
     %%%h( 1+ ((n-1)./2) ) = -h( 1+ ((n-1)./2) );
     %%%win = blackman(n);
     %%%h = h.*win.';
