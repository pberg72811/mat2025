function h = firBandPass(n,wc1,wc2)
     h1 = firLowPass(n,wc2);
     h2 = firHighPass(n,wc1);
     h = h1+h2;
