function xcom2xm(xcomHdrFile)
%
%
%
% DATAIMPORT - puts Midas header on a non-Midas data file
% 
% <data file>	Non-Midas data file
% <Midas file>	Name of Midas file
% <format>	Format of the data
% <elements>	Number of logical elements of <format> in the data
% <start>		Starting abscissa of the data
% <incr>		Abscissa increment
% <units>		Units code
% <offset>	Byte offset at which the data starts in <data file>
% <data rep>	Representation of the data, if other than native machine
% <data_opt>	Data handling option to pass to MDX
% 
% Makes data created by non-Midas processes readable by Midas commands by
% giving it a header.  The header will be detached, which doesn't matter to
% any X-Midas command; but it does mean that there are two separate files:
% header and data.  To combine them, you can NOOP the file to a new, attached
% file, or, if there are at least 512 unused bytes at the top of the data,
% ATTACH the header.  The advantage of simply adding a detached header is that
% if the file is very large, it will not be recopied in order to be Midas-
% readable.
% 
% The <elements> parameter must be specified if the <offset> parameter is
% greater than 0.  Otherwise, if <elements> is less than or equal to zero then
% the elements in the file will be determined based on the size of the
% <data file>.
% 
% The original data is renamed to <Midas file>.det, so the original name of
% <data file> will no longer be on disk.  The new <Midas file>, however, will
% be on the same aux as the old file.
% 
% SEE ALSO:  MDX,ATTACH
%       DATAIMPORT <data file> <Midas file> <format> <elements> <start>
%                  <incr> <units> <offset> <data rep> <data_opt>


    xcomInfo = readstruct(xcomHdrFile,"FileType","xml");
    cf = xcomInfo.captures.capture.center_frequencyAttribute;
    fs = xcomInfo.captures.capture.sample_rateAttribute;
    sampleBits = xcomInfo.data_files.data.sample_resolutionAttribute;
    totalSamples = xcomInfo.data_files.data.samplesAttribute;
    timeStr = xcomInfo.captures.capture.time_calibrationAttribute;
    iq_interleave = xcomInfo.data_files.data.iq_interleaveAttribute;
    nameAttribute = xcomInfo.data_files.data.nameAttribute;

    data_file = nameAttribute;
    elements = totalSamples;

    if     strcmpi(iq_interleave,"FALSE") && (sampleBits ==  8)
        format = "SB";
    elseif strcmpi(iq_interleave,"TRUE" ) && (sampleBits ==  8)
        format = "CB";
    elseif strcmpi(iq_interleave,"FALSE") && (sampleBits == 16)
        format = "SI";
    elseif strcmpi(iq_interleave,"TRUE" ) && (sampleBits == 16)
        format = "CI";
    else
        error("ERROR OR NEED NEW FORMAT TYPE.");
    end

    fprintf("DATAIMPORT %s ,, %s %d 0.0 %12.10g\n", data_file, format, elements, 1.0/fs);



    % fs = double( string(xcomInfo.sample_rate) );                   % Sample Rate.
    % cf = double( string(xcomInfo.center_frequency) );              % Center Frequency.
    % totalSamples = double( string(xcomInfo.samples) );             % Total samples in file.
    % sampleBits = double( string(xcomInfo.sample_resolution) );     % Number of bits in sample.
    % timeStr = string(xcomInfo.time_calibration);                   % Time tag string.
    dt = datetime(timeStr, "InputFormat","uuuu:DDD:HH:mm:ss.SSSS");  % Datetime tag.
    disp(dt);

end

function  mt = midastime(dt)
%
%
%
    posixtime(dt) + 