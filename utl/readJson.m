function json = readJson(fname)
%
%
%
    %fname = 'meta_Electronics.json'; 
    fid = fopen(fname); 
    raw = fread(fid,inf); 
    str = char(raw'); 
    fclose(fid); 
    json = jsondecode(str);
end