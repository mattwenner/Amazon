The Amazon executable will be made in the bin folder.

FOLLOW THESE DIRECTIONS!!!!

To compile the qt project program:

type: qmake -project

open the Amazon.pro and add: DESTDIR=bin #Target file directory OBJECTS_DIR=generated_files #Intermediate object files directory MOC_DIR=generated_files #Intermediate moc files directory

above "# Input"

scroll down and take out "splay.cpp"

save the Amazon.pro

type: qmake

type: make

Object files will be in the bin directory.

Intermediate object files and intermediate moc files will be in the generated_files folder.

To run the program, you need the executable created by the makefile and an input file from which information about the database is read. Again, the executable is in the bin folder. EX):

bin/./Amazon database.txt

