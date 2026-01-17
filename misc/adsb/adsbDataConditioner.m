clearvars

userPro = getenv("USERPROFILE");
dataDir = strcat(userPro,'\GIT25\ZDATA00');
adsbIn_File = strcat(dataDir,'\ADSB_Eclipse20240408.bin');
adsbOutFile = strcat(dataDir,'\ADSB_Eclipse20240408.txt');

fid_in = fopen(adsbIn_File,'r');
fid_ou = fopen(adsbOutFile,'w');

while ~feof(fid_in)
    line1 = fgetl(fid_in);
    if strcmpi(line1,"")
        continue
    % elseif length(line1) < 40
    %     continue
    else
        tmpSplt = split( line1, ';' );
        tmpStr0 = strrep(tmpSplt(1), "*", '');
        if length( char(tmpStr0) ) == 28
            fprintf("%s\n", tmpStr0);
            fprintf(fid_ou, "%s\n", tmpStr0);
        end
    end
end

fclose(fid_in);
fclose(fid_ou);