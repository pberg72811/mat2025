dataDir = getenv("USERPROFILE");
dataDir = strcat(dataDir,"\GIT25\ZDATA00");
h5File = strcat(dataDir,"\codar20250909.h5");

% h5File = "C:\Users\pbergman\GIT25\pmt2025\res\c2058001002.hdf5";
% h5File = "C:\Users\pbergman\GIT25\mat2025\hdf5\MYD16A2.A2025233.h28v07.061.2025248235713.hdf"
curNode = h5info(h5File);
examineGroup(curNode, h5File);

function examineGroup(node, h5File)
%
%
%
    if isempty(node.Datasets) == false
        for ii = 1:length(node.Datasets)
            if strcmpi(node.Name,"/")
                dsName = strcat(node.Name, node.Datasets(ii).Name);
            else
                dsName = strcat(node.Name, "/", node.Datasets(ii).Name);
            end
            fprintf("\n%s\n",dsName);
            theData = h5read(h5File, dsName);
            disp(theData)
        end
    end


    if isempty(node.Groups) == false
        for ii = 1:length(node.Groups)
            % fprintf("Group %s\n",node.Groups(ii).Name);
            examineGroup(node.Groups(ii), h5File)
        end
    end

end