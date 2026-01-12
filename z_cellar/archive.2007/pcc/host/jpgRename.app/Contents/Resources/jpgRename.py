#!/usr/bin/python
##----------------------------------------UNCLASSIFIED------------------------------------------
## File: jpgRename.py                                                                          -
##                                                                                             -
## Desc: This program renames JPEG pictures to a base name plus date, where the date is pulled -
##       from the actual date field found in the JPEG file.  As an example if the base name is -
##       "base" and the date of the JPEG file is January 1st at 10:22:00 then the file name    -
##       would come out to be:  base20050101_102200                                            -
##                                                                                             -
## Args: iFileName     - The name of the input file.                                           -
##       oFileNameBase - The name of the output file.                                          -
##                                                                                             -
## Hist: When       Who  What                                                                  -
##       03/05/2005 ptb  Initial Code.                                                         -
##       09/17/2005 ptb  Initial Code.                                                         -
##----------------------------------------------------------------------------------------------
import os;
import re;
import sys;
import time;


# testNewFileName
#-----------------------------------------------------------------------------------------------
def testNewFileName(newFileName,fileDex):
  thingString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if os.path.exists(newFileName):
    newFileName = newFileName + "%c" % (thingString[fileDex]);
    fileDex = fileDex + 1;
    newFileName = testNewFileName(newFileName,fileDex);
    return newFileName;
  else:
    return newFileName;

# writeNewMovFile
#-----------------------------------------------------------------------------------------------
def writeNewMovFile(oldFileName, newBaseFileName):
    
  fobj = open(oldFileName,'rb');                                      # Open the orignal file.
  fileString = fobj.read();                                           # Read the whole thing.
  fobj.close();                                                       # Close.

  fstats = os.stat(oldFileName);                                      # Get the stats on file.
  timeTag = time.gmtime(fstats.st_mtime);                             # Get time from stats.

  yearString = "%04d" %(timeTag.tm_year);                             # then use the os.stat data
  montString = "%02d" %(timeTag.tm_mon);                              # to create a time tag.
  day_String = "%02d" %(timeTag.tm_mday);                             #
  hourString = "%02d" %(timeTag.tm_hour);                             #
  min_String = "%02d" %(timeTag.tm_min);                              #
  sec_String = "%02d" %(timeTag.tm_sec);                              #

  print yearString;
  print montString;
  print day_String;
  print hourString;
  print min_String;
  print sec_String;

  newFileName = "";                                                   # Create new file name
  newFileName = newFileName + newBaseFileName;                        #
  newFileName = newFileName + yearString;                             #
  newFileName = newFileName + montString;                             #
  newFileName = newFileName + day_String;                             #
  newFileName = newFileName + "_" ;                                   #
  newFileName = newFileName + hourString;                             #
  newFileName = newFileName + min_String;                             #
  newFileName = newFileName + sec_String;                             #
  newFileName = newFileName + ".mov";                                 #

  newFileName = testNewFileName(newFileName,0);                       # Handle dublicates.

  print oldFileName;                                                  # Status.
  print newFileName;                                                  #
  print "------------------------------------------"                  #
  print "------------------------------------------"                  #

  fobj2 = open(newFileName,'wb');                                     # Open and write the
  fobj2.write(fileString);                                            # new file.
  fobj2.close();                                                      #

# writeNewJPGFile
#-----------------------------------------------------------------------------------------------
def writeNewJPGFile(oldFileName, newBaseFileName):
    
  fobj = open(oldFileName,'rb');                                      # Open the orignal file.
  fileString = fobj.read();                                           # Read the whole thing.
  fobj.close();                                                       # Close.

  fstats = os.stat(oldFileName);                                      # Get the stats on file.
  timeTag = time.gmtime(fstats.st_mtime);

  p = re.compile("....:..:.....:..:......");                          # Regular expression pattern.
  
  try:
    dateString = p.search(fileString[0:2048]).group();                # Look for the date string.
  except:                                                             #
    dateString = "00000000";                                          # If p.search fails.

  yearString  = dateString[0:4];                                      # Year string that was found.

  if yearString == "0000":                                            # If the year string is 0000
    yearString = "%04d" %(timeTag.tm_year);                           # then use the os.stat data
    montString = "%02d" %(timeTag.tm_mon);                            # to create a time tag.
    day_String = "%02d" %(timeTag.tm_mday);                           #
    hourString = "%02d" %(timeTag.tm_hour);                           #
    min_String = "%02d" %(timeTag.tm_min);                            #
    sec_String = "%02d" %(timeTag.tm_sec);                            #
  else:                                                               # Otherwise use the date
    yearString  = dateString[0:4];                                    # string that was found.
    montString  = dateString[5:7];                                    #
    day_String  = dateString[8:10];                                   #
    hourString  = dateString[11:13];                                  #
    min_String  = dateString[14:16];                                  #
    sec_String  = dateString[17:19];                                  #

  print yearString;
  print montString;
  print day_String;
  print hourString;
  print min_String;
  print sec_String;

  newFileName = "";                                                   # Create new file name
  newFileName = newFileName + newBaseFileName;                        #
  newFileName = newFileName + yearString;                             #
  newFileName = newFileName + montString;                             #
  newFileName = newFileName + day_String;                             #
  newFileName = newFileName + "_" ;                                   #
  newFileName = newFileName + hourString;                             #
  newFileName = newFileName + min_String;                             #
  newFileName = newFileName + sec_String;                             #
  newFileName = newFileName + ".jpg";                                 #

  newFileName = testNewFileName(newFileName,0);                       # Handle dublicates.

  print oldFileName;                                                  #
  print newFileName;                                                  #
  print "------------------------------------------"                  #
  print "------------------------------------------"                  #
  

  fobj2 = open(newFileName,'wb');                                     # Open and write the
  fobj2.write(fileString);                                            # new file.
  fobj2.close();                                                      #


# __main__
#-----------------------------------------------------------------------------------------------
if __name__ == '__main__':
  print sys.argv;
  print len(sys.argv);

  if (len(sys.argv) != 2):
    print("***********************************************************************************");
    print("Use : jpgRename directoryOfPictures baseName                                      -");
    print("                                                                                  -");
    print("Desc: This program renames JPEG pictures to a base name plus date, where the date -");
    print("      is pulled from the actual date field found in the JPEG file.  As an example -");
    print("      if the base name is \"base\" and the date in the JPEG file is January 1st at-");
    print("      10:22:00 then the file name would come out to be:  base20050101_102200      -");
    print("                                                                                  -");
    print("Args: directoryOfPictures - The name of the directory holding the files.          -");
    print("                                                                                  -");
    print("Note:                                                                             -");
    print("***********************************************************************************");
        
  else:
    programFileName = sys.argv[0];
    directoryOPICS  = sys.argv[1];
        
    print programFileName;
    print directoryOPICS;
    
    for r, dList, fList in os.walk(directoryOPICS):
      for file in fList:
        pathName = "%s" % (r)
        fileName = "%s" % (file)
        pathFileName = "%s/%s" % (pathName,fileName)
        j = len(fileName)
        i = len(fileName)-3
        fileType = str(fileName[i:j]);
        fileType = fileType.upper();
        if fileType == "JPG":
          print "This is a JPEG";
          writeNewJPGFile(pathFileName, "pic");
        elif fileType == "MOV":
            print "This is a MOV"
            writeNewMovFile(pathFileName, "mov");
        #else:
        #print "This is not a JPEG or a Mov"; 






##global picCounter;
##global movCounter;
##global cYear;
##global cMont;
##global cDayy;


###
###-----------------------------------------------------------------------------------------------

##def readAtom(fileString,ii):
##  jj = ii+8;
##  size,c1,c2,c3,c4 = struct.unpack('>Lcccc',fileString[ii:jj]);
##  type = c1 + c2 + c3 + c4;
##  print size;
##  print type;
    
##  if ii < len(fileString):
##    if type == "mdat":
##      print "FOUND MDAT"
##      print "ii is %d" %(ii)
##      #readAtom(fileString,ii+8);
##    else:
##      readAtom(fileString,ii+size);
##    else:
##      return();
    
##def writeNewMovFile(oldMovFileName, newBaseFileName):
##  global movCounter;
    
##  fobj = open(oldMovFileName,'rb');                                # Open the orignal file.
##  fileString = fobj.read();                                        # Read the whole thing.
##  fobj.close();                                                    # Close.
    
##  print len(fileString);
    
##  secString   = "%04d" % (movCounter);
##  movCounter = movCounter + 1;

##  newFileName =  "";
##  newFileName = newFileName + newBaseFileName;
##  #newFileName = newFileName + yearString;
##  #ewFileName = newFileName + monthString;
##  #newFileName = newFileName + dayString;
##  #newFileName = newFileName +  "_" ;
##  #newFileName = newFileName + hourString;
##  #newFileName = newFileName + minString;
##  newFileName = newFileName + secString;
##  newFileName = newFileName + ".mov";
  
  
##  fobj2 = open(newFileName,'wb');
##  fobj2.write(fileString);
##  fobj2.close();
  
  #readAtom(fileString,0);
    
#    ii = 0;
#    jj = ii+8;
#    size,c1,c2,c3,c4 = struct.unpack('>Lcccc',fileString[ii:jj]);
#    type = c1 + c2 + c3 + c4;
#    print size;
#    print type;
    
#    if type == "mdat":
#        iii = 8;
#        jjj = iii+8;    
#        sizex,c1x,c2x,c3x,c4x = struct.unpack('>Lcccc',fileString[ii:jj]);
#        typex = c1x + c2x + c3x + c4x;
#        print sizex;
#        print typex;
# 
#    
#    ii = ii+size;
#    jj = ii+8;
#    size,c1,c2,c3,c4 = struct.unpack('>Lcccc',fileString[ii:jj]);
#    type = c1 + c2 + c3 + c4;
#    print size;
#    print type;   
#    ii = ii+size;
#    jj = ii+8;
#    size,c1,c2,c3,c4 = struct.unpack('>Lcccc',fileString[ii:jj]);
#    type = c1 + c2 + c3 + c4;
#    print size;
#    print type;   
#    ii = ii+size;
#    jj = ii+8;
#    size,c1,c2,c3,c4 = struct.unpack('>Lcccc',fileString[ii:jj]);
#    type = c1 + c2 + c3 + c4;
#    print size;
#    print type;

# writeNewMovFile
#-----------------------------------------------------------------------------------------------

##  ii = 0;
##  for aChar in fileString:                                         # Go look for the first
##    if aChar == ':':                                               # occurance of an ":"
##      print "Found one at %ld" %(ii);
##      if ii > 1024:
##	return();
##      if fileString[ii+3] == ':':
##	if fileString[ii+9] == ':':
##	  if fileString[ii+12] == ':':
##	    timeString  = fileString[(ii-4):(ii+15)];
##	    yearString  = timeString[0:4];
##	    monthString = timeString[5:7];
##	    dayString   = timeString[8:10];
##	    hourString  = timeString[11:13];
##	    minString   = timeString[14:16];
##	    secString   = timeString[17:19];
                            
##	    if yearString == "0000":
##	      yearString  = "%d" % (cYear);
##	      monthString = "%d" % (cMont);
##	      dayString   = "%d" % (cDayy);
##	      secString   = "%04d" % (picCounter);
##	      picCounter  = picCounter + 1;
                              
                            
##	      newFileName = "";
##	      newFileName = newFileName + newBaseFileName;
##	      newFileName = newFileName + yearString;
##	      newFileName = newFileName + monthString;
##	      newFileName = newFileName + dayString;
##	      newFileName = newFileName +  "_" ;
##	      newFileName = newFileName + hourString;
##	      newFileName = newFileName + minString;
##	      newFileName = newFileName + secString;
##	      newFileName = newFileName + ".jpg";
                                                        
##	      print timeString;
##	      print yearString;
##	      print monthString;
##	      print dayString;
##	      print hourString;
##	      print minString;
##	      print secString;
##	      print newFileName;
                            
##	      fobj.close();
                        
##	      fobj2 = open(newFileName,'wb');
##	      fobj2.write(fileString);
##	      fobj2.close();
                            
##	      break;
##            ii = ii + 1;
##        else:
##            ii = ii + 1;
            
        
##    print "Done!"
##    return();
            
#------------------------------------------------------------------------------------------------
