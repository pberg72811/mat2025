classdef audioBufferClass < handle
%------------------------------------------UNCLASSIFIED-------------------------------------------
% Name: audioBufferClass.m
%
% Dscr: Create a "wav" file audio buffer object that can return chucks of data incrementally.
%
% Hist: Who   When       What
%       ptb   08/01/25   Initial code.
%
%-------------------------------------------------------------------------------------------------
    properties
    %
        fs;                  % Sample rate.
        ns;                  % Number of samples.
        buffer;              % Buffer for audio data.
        strtDex;             % Starting index of data.
        stopDex;             % Stopping index of data. 
        metaData;            % Meta data.
    end

    methods %-------------------------------------------------------------------------------------
    %
      function obj = audioBufferClass(fileName)
      %
      % obj = audioBufferClass(fileName)
      %
      % INPUTS_: FileName
      % OUTPUTS: Object built from class.
      %
      % Constructor. Read meta data and audio data from "wav" file.
      %-------------------------------------------------------------------------------------------
        obj.buffer = [];
        obj.metaData = audioinfo(fileName);                        % Read "wav" file meta data.
        [obj.buffer, obj.fs] = audioread(fileName);                % Read all of "wav" file.
        obj.ns = length(obj.buffer);
        obj.strtDex = 1;                                           % Initialize starting index.
        obj.stopDex = 0;                                           % Stop index is TBD.
      end

      function resBuffer = getSamples(obj, nSamples)
      %
      % resBuffer = getSamples(obj, nSamples)
      %
      % INPUTS_: Number of samples.
      % OUTPUTS: Buffer containing audio samples.
      % 
      % Return nSamples from "wav" file in "resBuffer" and update internal indexes.
      % There is an assumption that the audio data is complex.
      %-----------------------------------------------------------------------------------------
        obj.stopDex = obj.stopDex + nSamples;                        % Define stop index.

        if obj.strtDex > obj.ns                                      % Constrain starting index
          obj.strtDex = 1;                                           % to total samples
          obj.stopDex = nSamples;                                    % 
        end                                                          % 

        if obj.stopDex <= obj.ns                                     % Constrain stopping index
          resBuffer = obj.buffer(obj.strtDex:obj.stopDex,1) + ...    % to total samples.
                      obj.buffer(obj.strtDex:obj.stopDex,2)*1i;      % 
  
          obj.strtDex = obj.strtDex + nSamples;                      % Update strtDex for next
          %                                                          % call.
        else
          strt = obj.strtDex;                                        % Handle Buffer Wrap.
          stop = obj.ns;                                             %
          stop2 = obj.stopDex - stop;                                %
          resBufferA = obj.buffer( strt:stop, 1 ) + ...              %
                       obj.buffer( strt:stop, 2 )*1i;                %
          resBufferB = obj.buffer(1:stop2, 1) + ...                  %
                       obj.buffer(1:stop2, 2)*1i;                    %
          resBuffer = [resBufferA; resBufferB];                      %

          obj.strtDex = stop2 + 1;                                   % Update strtDex and stopDex
          obj.stopDex = stop2;                                       % for next call.
          
        end

      end

    end

    methods(Static) %-----------------------------------------------------------------------------

      function ttag = getTimeTag(audioFileName)
      %
      % ttag = getTimeTag(audioFileName)
      %
      % INPUTS_: File name of SDR# "wav" file.
      % OUTPUTS: Time tag in POSIX format.
      % 
      % Static method to create time tag from SDR# "wav" file.
      % Example file name: "SDRSharp_20250822_132632Z_3430000Hz_IQ.wav"
      %-------------------------------------------------------------------------------------------
        tmpStr00 = strsplit(audioFileName, '\');
        tmpStr01 = strsplit(tmpStr00(end),'.');
        tmpStr02 = strsplit(tmpStr01(1),'_');
        yymmdd = tmpStr02(2);
        hhmmss = tmpStr02(3);
        hhmmss = strrep(hhmmss,'Z','');
        yyyyMMddHHmmss = strcat(yymmdd,hhmmss);
        dt01 = datetime(yyyyMMddHHmmss, "Format", "yyyyMMddHHmmss", "TimeZone", "UTC");
        ttag = posixtime(dt01)*1000;
      end

    end
end