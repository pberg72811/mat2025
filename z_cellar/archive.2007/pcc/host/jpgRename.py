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
  newFileName = newFileName + "/1_Dad/zPictureProcessing/"
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
  newFileName = newFileName + "/1_Dad/zPictureProcessing/"
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
  
  listOfPictureDirectories = [];
  #listOfPictureDirectories.append("/Users/DakiG/Pictures/iPhotoLibrary/Originals/2010");
  listOfPictureDirectories.append("/Users/DakiG/Pictures/iPhotoLibrary/Originals/2011");
  
  
  for pictureDirectory in listOfPictureDirectories:
  	for r, dList, fList in os.walk(pictureDirectory):
			for file in fList:
				pathName = "%s" % (r);
				fileName = "%s" % (file);
				pathFileName = "%s/%s" % (pathName,fileName);
				j = len(fileName);
				i = len(fileName)-3;
				fileType = str(fileName[i:j]);
				fileType = fileType.upper();
				if fileType == "JPG":
					print "This is a JPEG";
					writeNewJPGFile(pathFileName, "pic");
				elif fileType == "MOV":
					print "This is a MOV";
					writeNewMovFile(pathFileName, "mov");
