# Simple Testing Script for Assignment 1 
# 
# Builds program and tests for two simple cases.
# 
# How to use:
#	- Copy this file to the directory you're using to store your program.
#	- If this file, once copied, can't be run using test.sh, you may need
#		to run `chmod 777 test.sh` in your terminal window.
#	- Compile your program as usual.
#	- You can feel free to use this program for your own testing, we would 
#		however recommend you ensure your program still executes on the original
#		version of this file.
#	- You may like to explain what you think the output should be using the echo
#		command, so you know what to expect from your program.
#	- After saving your changes, you can run this script using test.sh.
#
# NOTE: This is in no sense a complete set of test cases, you'll need to write
#	some of your own to ensure your program is correct.
#
# NOTE2: This program will overwrite any file you have called exactly datafile,
#	datafile2, keyfile or keyfile2.
#
# Written by Grady Fitzpatrick (Staff Number 110064, Student 575753) for 
# COMP20003, Algorithms and Data Structures

# Removes .o files and the autocomplete programs, to make sure you're not 
# building something 
rm -f *.o autocomplete1 autocomplete2

# -B forces make to make the programs even if they are up to date.
echo "Making autocomplete1 and autocomplete2"
make autocomplete1 -B
make autocomplete2 -B

# Test data, one word "a", searched for by the keyfile.
TESTDATAFILE1="5;a"
TESTKEYFILE1="a"

# Second Test data, one word "b", searched for by the keyfile.
TESTDATAFILE2="6;b"
TESTKEYFILE2="b"

# Output test data to files named datafile, keyfile, datafile2 and keyfile2
printf "$TESTDATAFILE1" > datafile
printf "$TESTKEYFILE1" > keyfile
printf "$TESTDATAFILE2" > datafile2
printf "$TESTKEYFILE2" > keyfile2

# Run the tests on both programs.
echo "Running autocomplete1 datafile outputfile < keyfile"
autocomplete1 datafile outputfile < keyfile
echo "Contents of outputfile"
cat outputfile

echo "Running autocomplete1 datafile2 outputfile2 < keyfile2"
autocomplete1 datafile2 outputfile2 < keyfile2
echo "Contents of outputfile2"
cat outputfile2

echo "Running autocomplete2 datafile outputfile < keyfile"
autocomplete2 datafile outputfile < keyfile
echo "Contents of outputfile"
cat outputfile

echo "Running autocomplete2 datafile2 outputfile2 < keyfile2"
autocomplete2 datafile2 outputfile2 < keyfile2
echo "Contents of outputfile2"
cat outputfile2
