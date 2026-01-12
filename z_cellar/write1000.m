function [h,d] = write1000(filePath, data, fs, ts)
  % Write data to X-Midas type 1000 file.
  %
  % WRITE1000(filePath, data) write 'data' to 'filePath.'
  % WRITE1000(filePath, data, fs) write 'data' to 'filePath' specify sample rate 'fs.'
  % WRITE1000(filePath, data, fs, ts) write 'data' to 'filePath' using 'fs' and specify time stamp 'ts.'
  %
  if  (nargin == 0)
    error("WRONG NUMBER OF ARGUMENTS.");
  elseif (nargin == 1)
    error("WRONG NUMBER OF ARGUMENTS.");
  elseif (nargin == 2)
    fs = 1.0;
    ts = currentJ1950();
  elseif (nargin == 3)
    ts = currentJ1950();
  elseif (nargin == 4)
    % Do nothing;
  else
    error("WRONG NUMBER OF ARGUMENTS.");
  end%if
  
  
  fid = fopen(filePath,"w","ieee-le");
    
  nPoints  = length(data);
  
  if     ( isa(data,"int8") )
    format = 'SB';
    dataSizeBytes = nPoints * 1;
  elseif ( isa(data,"uint8") )
    format = 'SB';
    dataSizeBytes = nPoints * 1;
  elseif ( isa(data,"int16") )
    format = 'SI';
    dataSizeBytes = nPoints * 2;
  elseif ( isa(data,"uint16") )
    format = 'SI';
    dataSizeBytes = nPoints * 2;
  elseif ( isa(data,"int32") )
    format = 'SL';
    dataSizeBytes = nPoints * 4;
  elseif ( isa(data,"uint32") )
    format = 'SL';
    dataSizeBytes = nPoints * 4;
  elseif ( isa(data,"int64") )
    format = 'SX';
    dataSizeBytes = nPoints * 8;
  elseif ( isa(data,"uint64") )
    format = 'SX';
    dataSizeBytes = nPoints * 8;
  elseif ( isa(data,"single") )
    format = 'SF';
    dataSizeBytes = nPoints * 4;
  elseif ( isa(data,"double") )
    format = 'SD';
    dataSizeBytes = nPoints * 8;
  end
  
  if (iscomplex(data))
    strrep(format, "S", "C");
    dataSizeBytes = dataSizeBytes * 2;
  end
 
  fwrite(fid, "BLUE",                     "char");         %% ver
  fwrite(fid, "EEEI",                     "char");         %% hdr_rep
  fwrite(fid, "EEEI",                     "char");         %% data_rep
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% detached
  fwrite(fid, cast(1, "int32"),           "integer*4");    %% protected
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% pipe
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% ext_start
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% ext_size
  fwrite(fid, 512.0,                      "real*8");       %% data_start
  fwrite(fid, dataSizeBytes,              "real*8");       %% data_size
  fwrite(fid, cast(1000, "int32"),        "integer*4");    %% type
  fwrite(fid, format,                     "char");         %% format
  fwrite(fid, cast(0, "int16"),           "integer*2");    %% flagmask
  fwrite(fid, ts,                         "real*8");       %% timecode
  fwrite(fid, cast(0, "int16"),           "integer*2");    %% inlet
  fwrite(fid, cast(0, "int16"),           "integer*2");    %% outlets
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% outmask
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% pipeloc
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% pipesize
  fwrite(fid, 0.0,                        "real*8");       %% in_byte
  fwrite(fid, 0.0,                        "real*8");       %% out_byte
  fwrite(fid, zeros(1,8),                 "real*8");       %% outbytes
  fwrite(fid, cast(19, "int32"),          "integer*4");    %% keylength
  fwrite(fid, "ABCDEFGHIJKLMNOPQR\n",     "char");         %%
  fwrite(fid, cast(zeros(1,92-19), "uint8"), "char");      %% keyword fill
  %% Adjunct.                                              %% Adjunct.
  fwrite(fid, 0.0,                        "real*8");       %% abscissa start
  fwrite(fid, 1/fs,                       "real*8");       %% abscissa delta
  fwrite(fid, cast(0, "int32"),           "integer*4");    %% abscissa units

  fwrite(fid, cast(zeros(1,236), "uint8"), "char");        %% adjunct fill

  if     ( strncmpi(format, "SB", 2) ) %----------------------------- RINT08
    fwrite(fid, data, "int8");
  elseif ( strncmpi(format, "SI", 2) ) %----------------------------- RINT16
    fwrite(fid, data, "int16");
  elseif ( strncmpi(format, "SL", 2) ) %----------------------------- RINT32
    fwrite(fid, data, "int32");
  elseif ( strncmpi(format, "SX", 2) ) %----------------------------- RINT64
    fwrite(fid, data, "int64");
  elseif ( strncmpi(format, "SF", 2) ) %----------------------------- RFLT32
    fwrite(fid, data, "real*4");
  elseif ( strncmpi(format, "CF", 2) ) %----------------------------- CFLT32
    for ii = 1:nPoints
      fwrite(fid, real(data(ii)), "real*4");
      fwrite(fid, imag(data(ii)), "real*4");
    end
  elseif ( strncmpi(format, "SD", 2) ) %----------------------------- RFLT64
    fwrite(fid, data, "real*8");
  elseif ( strncmpi(format, "CD", 2) ) %----------------------------- CFLT32
    for ii = 1:nPoints
      fwrite(fid, real(data(ii)), "real*8");
      fwrite(fid, imag(data(ii)), "real*8");
    end 
  end%if

  fclose(fid);

  h = 1;
  d = 2;

end


%% BLUE Header Fields
%% 
%% Offset  Name         Size  Type     Description
%% 
%%   0     version      4     char[4]  Header version
%%   4     head_rep     4     char[4]  Header representation
%%   8     data_rep     4     char[4]  Data representation
%%  12     detached     4      int_4   Detached header
%%  16     protected    4      int_4   Protected from overwrite
%%  20     pipe         4      int_4   Pipe mode (N/A)
%%  24     ext_start    4      int_4   Extended header start, in 512-byte blocks
%%  28     ext_size     4      int_4   Extended header size in bytes
%%  32     data_start   8     real_8   Data start in bytes
%%  40     data_size    8     real_8   Data size in bytes
%%  48     type         4      int_4   File type code
%%  52     format       2     char[2]  Data format code
%%  54     flagmask     2      int_2   16-bit flagmask (1=flagbit)
%%  56     timecode     8     real_8   Time code field
%%  64     inlet        2      int_2   Inlet owner
%%  66     outlets      2      int_2   Number of outlets
%%  68     outmask      4      int_4   Outlet async mask
%%  72     pipeloc      4      int_4   Pipe location
%%  76     pipesize     4      int_4   Pipe size in bytes
%%  80     in_byte      8     real_8   Next input byte
%%  88     out_byte     8     real_8   Next out byte (cumulative)
%%  96     outbytes    64   real_8[8]  Next out byte (each outlet)
%% 160     keylength    4      int_4   Length of keyword string
%% 164     keywords    92    char[92]  User defined keyword string
%% 256     adjunct    256   char[256]  Type-specific adjunct union
%%
%% Use LINUX octal dump "od" to get header vaules from file.
%%
%% data_start      od -A d -j 32  -N 8  -t f8 $XMDISK/xm/dat/map1.prm
%% data_size       od -A d -j 40  -N 8  -t f8 $XMDISK/xm/dat/map1.prm 
%% type            od -A d -j 48  -N 4  -t d4 $XMDISK/xm/dat/map1.prm
%% format          od -A d -j 52  -N 2  -t c  $XMDISK/xm/dat/map1.prm
%% keylength       od -A d -j 160 -N 4  -t d4 $XMDISK/xm/dat/map1.prm
%% keywords        od -A d -j 164 -N 92 -t c  $XMDISK/xm/dat/map1.prm
%%
%% Adjunct.
%% abscissa start  od -A d -j 256 -N 8  -t f8 $XMDISK/xm/dat/map1.prm
%% abscissa delta  od -A d -j 264 -N 8  -t f8 $XMDISK/xm/dat/map1.prm
%% abscissa units  od -A d -j 272 -N 8  -t f8 $XMDISK/xm/dat/map1.prm
%%
%% @end example
%%
%% @deftypefn { [H,D] = write1999 ( fileNamePath, data) }
%%
%% Write X-Midas type 1000 file.
%%
%% @end deftypefn