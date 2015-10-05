POSIX Regex functions for DataFlex 3.2
--------------------------------------

Requires:
	DataFlex 3.1c onwards
	GCC or compatible compiler like MinGW
	GNU regex libraries for windows 
		http://sourceforge.net/projects/mingw/files/Other/UserContributed/regex

I created this because despite VDF (Visual Dataflex) users being able to leverage
vbscript.dll in Windows via COM to do regex operations, it seems that Console Mode 
users are out of luck.

Despite being GNU libraries, this is intended to be used on Microsoft Windows
using the DataFlex external_function import.  No doubt if you're using DataFlex
on Unix you can get these to work with minimal modifications.
