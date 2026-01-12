function y = round2Even(x)
  y = x/10;
  y = fix(y);
  y = y/10;
  if( rem(fix(y),2) ==0 ),
    if( (y-fix(y))== 0.5 ), y = fix(y);
    else,                   y = round(y);
    end
  else,
    if( (y-fix(y))== 0.5 ), y = ceil(y);
    else,                   y = round(y);
    end
  end
