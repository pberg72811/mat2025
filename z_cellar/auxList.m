function theList = auxList()
%
%
  directory = getenv("USERPROFILE");              % USERPROFILE


  theList = auxListPart2(directory,   0);
  
  directory = 'C:\Users\bergm\OneDrive\GIT25';    % One Drive

  theList2 = auxListPart2(directory, 90);

  disp(theList2);

  % git25Dir = strcat(user_Dir,"\GIT25");          % GIT25
  % 
  % for ii = 0:10                                  % ZDATA00, ZDATA001, ect.
  %   jj = ii +1;
  %   directory = sprintf("\\ZDATA%02d", ii);
  %   dataDir = strcat(git25Dir,directory); 
  %   if isfolder(dataDir)
  %     theList(jj).aux = dataDir; %#ok<AGROW>
  %   end 
  % end
  
end

function theList = auxListPart2(direPath, offset)
%
%
%
  git25Dir = strcat(direPath,"\GIT25");         % GIT25
  
  for ii = 0:9                                  % ZDATA00, ZDATA001, ect.
    jj = ii + 1;
    directory = sprintf("\\ZDATA%02d",  ii + offset);
    dataDir = strcat(git25Dir, directory); 
    if isfolder(dataDir)
      theList(jj).aux = dataDir; %#ok<AGROW>
    end 
  end

end