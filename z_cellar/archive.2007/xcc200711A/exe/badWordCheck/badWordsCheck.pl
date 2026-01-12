#!/usr/bin/perl
#------------------------------------------------------------------------------------------------
#-----------------------------------------UNCLASSIFIED-------------------------------------------
# File: badWordsCheck.pl
# Desc:
# Hist: When       Who  What
#       05/24/2005 ptb  Initial Code.
#------------------------------------------------------------------------------------------------
$NARG            = scalar(@ARGV);
$SCRIPT_NAME     = $0;
$sourceFileName  = $ARGV[0];
$dirtyPhraseFile = $ARGV[1];

# Open the dirty word file.
#------------------------------------------------------------------------------------------------
open($input, $dirtyPhraseFile);

# Get a list of dirty phrases going.
#------------------------------------------------------------------------------------------------
$ii=0;                                                # Initialize the array index.
while (<$input>)                                      # Go through each line of bad word file.
{                                                     #
  chomp;                                              # Get rid of ending return character.
  $STRING[$ii] = $_;                                  # Set STRING variable to the current line.
  $ii++;                                              # Increment array index.
}                                                     #------------------------------------------

# Close the dirty phrase file.
#------------------------------------------------------------------------------------------------
close($input);

# Step through each dirty phase and check the source file.
#------------------------------------------------------------------------------------------------
$ii=0;
for(@STRING)                                          # For each value in the STRING array.
{                                                     #
  printf("Checking for $STRING[$ii]\n");              # Let the world knonw where we are.
  system("cat $sourceFileName | badPhraseCheck $STRING[$ii]\n"); # Execute a "grep" command.
  $ii++;                                              #
}                                                     #------------------------------------------
