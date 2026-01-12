function [bh] = writeBlueFileHeader(fid, bh)
  %
  %
  fwrite( fid, bh.version,    class(bh.version) );    disp(class(bh.version))
  fwrite( fid, bh.head_rep,   class(bh.head_rep) );   disp(class(bh.head_rep))
  fwrite( fid, bh.data_rep,   class(bh.data_rep) );   disp(class(bh.data_rep))
  fwrite( fid, bh.detached,   class(bh.detached) );   disp(class(bh.detached))
  fwrite( fid, bh.protected,  class(bh.protected) );  disp(class(bh.protected))
  fwrite( fid, bh.pipe,       class(bh.pipe) );       disp(class(bh.pipe))
  fwrite( fid, bh.ext_start,  class(bh.ext_start) );  disp(class(bh.ext_start))
  fwrite( fid, bh.ext_size,   class(bh.ext_size) );   disp(class(bh.ext_size));
  fwrite( fid, bh.data_start, class(bh.data_start) ); disp(class(bh.ext_size));
  fwrite( fid, bh.data_size,  class(bh.data_size) );  disp(class(bh.ext_size));
  fwrite( fid, bh.ext_type,   class(bh.ext_type) );
  fwrite( fid, bh.format,     class(bh.format) );
  fwrite( fid, bh.flagmask,   class(bh.flagmask) );
  fwrite( fid, bh.timecode,   class(bh.timecode) );
  fwrite( fid, bh.inlet,      class(bh.inlet) );
  fwrite( fid, bh.outlets,    class(bh.outlets) );
  fwrite( fid, bh.pipeloc,    class(bh.pipeloc) );
  fwrite( fid, bh.outmask,    class(bh.outmask) );
  fwrite( fid, bh.pipesize,   class(bh.pipesize) );
  fwrite( fid, bh.in_byte,    class(bh.in_byte) );
  fwrite( fid, bh.out_byte,   class(bh.out_byte) );
  fwrite( fid, bh.outbytes,   class(bh.outbytes) );
  fwrite( fid, bh.keylength,  class(bh.keylength) );
  fwrite( fid, bh.keywords,   class(bh.keywords) );
    
  if     bh.ext_type == 1000

    fwrite( fid, bh.xstart, class(bh.xstart) ); disp(class(bh.xstart));
    fwrite( fid, bh.xdelta, class(bh.xdelta) ); disp(class(bh.xdelta));
    fwrite( fid, bh.xunits, class(bh.xunits) ); disp(class(bh.xunits));
    fwrite( fid, bh.pad,    class(bh.pad) );    disp(class(bh.pad));

  elseif bh.ext_type == 2000

    fwrite( fid, bh.xstart,  class(bh.xstart) );  disp(class(bh.xstart));
    fwrite( fid, bh.xdelta,  class(bh.xdelta) );  disp(class(bh.xdelta));
    fwrite( fid, bh.xunits,  class(bh.xunits) );  disp(class(bh.xunits));
    fwrite( fid, bh.subsize, class(bh.subsize) ); disp(class(bh.subsize));
    fwrite( fid, bh.ystart,  class(bh.xstart) );  disp(class(bh.xstart));
    fwrite( fid, bh.ydelta,  class(bh.xdelta) );  disp(class(bh.xdelta));
    fwrite( fid, bh.yunits,  class(bh.xunits) );  disp(class(bh.xunits));
    fwrite( fid, bh.pad,     class(bh.pad) );     disp(class(bh.pad));

  end

end