 fp = fopen("/mnt/cdrom/MS110A39T_WAV/A0300AL.wav","r","ieee-le");
 ##fp = fopen("test.wav","r");
 formatString    = fread(fp,4,'char');
 nChunkSize      = fread(fp,1,'uint32');
 formatTag       = fread(fp,1,'uint16');
 nChannels       = fread(fp,1,'uint16');
 nSampleRate     = fread(fp,1,'int32');
 nAvgBytesPerSec = fread(fp,1,'uint32');
 nBlockAlign     = fread(fp,1,'uint16');
 nBitsPerSample  = fread(fp,1,'uint16');
 data            = fread(fp,64*1024,'uint16');

 formatString
 nChunkSize
 formatTag
 nChannels
 nSampleRate
 nAvgBytesPerSec
 nBlockAlign
 nBitsPerSample

 fclose(fp);



