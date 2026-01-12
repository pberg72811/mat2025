function [bh] = readBlueFileHeader(fid)
  
  bh.version    =  char( fread(fid,   4, "char")  ); %#ok<FREAD>
  bh.head_rep   =  char( fread(fid,   4, "char")  ); %#ok<FREAD>
  bh.data_rep   =  char( fread(fid,   4, "char")  ); %#ok<FREAD>
  bh.detached   = int32( fread(fid,   1, "int32") );
  bh.protected  = int32( fread(fid,   1, "int32") );
  bh.pipe       = int32( fread(fid,   1, "int32") );
  bh.ext_start  = int32( fread(fid,   1, "int32") );
  bh.ext_size   = int32( fread(fid,   1, "int32") );
  bh.data_start =        fread(fid,   1, "float64");
  bh.data_size  =        fread(fid,   1, "float64");
  bh.ext_type   = int32( fread(fid,   1, "int32") );
  bh.format     =  char( fread(fid,   2, "char")  ); %#ok<FREAD>
  bh.flagmask   = int16( fread(fid,   1, "int16") );
  bh.timecode   =        fread(fid,   1, "float64");
  bh.inlet      = int16( fread(fid,   1, "int16") );
  bh.outlets    = int16( fread(fid,   1, "int16") );
  bh.pipeloc    = int32( fread(fid,   1, "int32") );
  bh.outmask    = int32( fread(fid,   1, "int32") );
  bh.pipesize   = int32( fread(fid,   1, "int32") );
  bh.in_byte    =        fread(fid,   1, "float64");
  bh.out_byte   =        fread(fid,   1, "float64");
  bh.outbytes   =        fread(fid,   8, "float64");
  bh.keylength  = int32( fread(fid,   1, "int32") );
  bh.keywords   =  char( fread(fid,  92, "char")  ); %#ok<FREAD>
  %bh.adjunct    =  char( fread(fid, 256, "char")  ); %#ok<FREAD>
  
  if     bh.ext_type == 1000
    bh.xstart   =        fread(fid,   1, "float64");
    bh.xdelta   =        fread(fid,   1, "float64");
    bh.xunits   = int32( fread(fid,   1, "int32") );
    bh.pad      =  char( fread(fid, 235, "char")  ); %#ok<FREAD>
  elseif bh.ext_type == 2000
    bh.xstart   =        fread(fid,   1, "float64");
    bh.xdelta   =        fread(fid,   1, "float64");
    bh.xunits   = int32( fread(fid,   1, "int32") );
    bh.subsize  = int32( fread(fid,   1, "int32") );
    bh.ystart   =        fread(fid,   1, "float64");
    bh.ydelta   =        fread(fid,   1, "float64");
    bh.yunits   = int32( fread(fid,   1, "int32") );
    bh.pad      =  char( fread(fid, 212, "char")  ); %#ok<FREAD>
  elseif bh.ext_type == 5001
    %bh = handleType5001(fid,bh);
  end
  
end