function [EPS, XINCL, XNO, XMO, EO, OMEGAO, XNODEO, XNDT2O, XNDD6O] = convertTLE(tle1, tle2)
%
% Convert Two Line Element to orbital parameters.
%
   tle1 = strip(tle1);
   tle2 = strip(tle2);

   crdNo = tle1(1);                    %#ok<NASGU>
   space = tle1(2);                    %#ok<NASGU>
   satNo = tle1(3:7);                  %#ok<NASGU>
   class = tle1(8);                    %#ok<NASGU>
   space = tle1(9);                    %#ok<NASGU>
   year_ = tle1(10:11);                %#ok<NASGU>
   launc = tle1(12:14);                %#ok<NASGU>
   piece = tle1(15:17);                %#ok<NASGU>
   space = tle1(18);                   %#ok<NASGU>
   epoch = tle1(19:32);
   space = tle1(33);                   %#ok<NASGU>
   XNDT2O = str2double(tle1(34:43));
   space = tle1(44);                   %#ok<NASGU>
   XNDD6O = tle1(45:52);
   space = tle1(53);                   %#ok<NASGU>
   BSTAR = tle1(54:61);
   space = tle1(62);                   %#ok<NASGU>
   eph_t = tle1(63);                   %#ok<NASGU>
   space = tle1(64);                   %#ok<NASGU>
   next_ = tle1(65:68);                %#ok<NASGU>
   chksm = tle1(69);                   %#ok<NASGU>

   epochYear = str2double(epoch(1:2));
   epochDay  = str2double(epoch(3:end));
   EPS = norad2Seconds(epochYear, epochDay);

   XNDD6O = str2double(bStarNumberConversion(XNDD6O));
   BSTAR = str2double(bStarNumberConversion(BSTAR)); %#ok<NASGU>


   crdNo = tle2(1);                    %#ok<NASGU>
   space = tle2(2);                    %#ok<NASGU>
   satNo = tle2(3:7);                  %#ok<NASGU>
   space = tle2(8);                    %#ok<NASGU>
   XINCL = str2double(tle2(9:16));
   space = tle2(17);                   %#ok<NASGU>
   XNODEO = str2double(tle2(18:25));
   space = tle2(26);                   %#ok<NASGU>
   EO = str2double(['.' tle2(27:33)]);
   space = tle2(34);                   %#ok<NASGU>
   OMEGAO = str2double(tle2(35:42));
   space = tle2(43);                   %#ok<NASGU>
   XMO = str2double(tle2(44:51));
   space = tle2(52);                   %#ok<NASGU>
   XNO = str2double(tle2(53:63));
   eporv = tle2(64:68);                %#ok<NASGU>
   chksm = tle1(69);                   %#ok<NASGU>


end


function bStarStr = bStarNumberConversion(bStar)
%
% Goes for XNDD6O also
%
   if(bStar(1) == '-')     % '-00000+0'
      bStar(1) = ' ';
      unity = -1;
   elseif(bStar(1) == '+') % '+00000+0' Should never happen ' 00000+0'
      bStar(1) = ' ';
      unity = +1;
   else
      unity = +1;
   end

   bStarStr = ['0.' strip(bStar) ];
   bStarStr = strrep(bStarStr,'-','e-');
   bStarStr = strrep(bStarStr,'+','e+');
   
   if unity < 0
      bStarStr = ['-' bStarStr];
   end
end


function sec = norad2Seconds( yy, day )
%
% Return epoch 1970 seconds from  NORAD year/day date.
%
   if yy < 50
      yyyy = yy + 2000;
   else
      yyyy = yy + 1900;
   end

   tmp = datetime(yyyy, 1, 1, 0, 0, 0);
   sec = posixtime(tmp) + ( ( day - 1.0 ) * 86400 );

end