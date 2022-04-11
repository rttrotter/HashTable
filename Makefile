#
# PROGRAM:    assign9
# PROGRAMMER: Tyler Trotter
# LOGON ID:   z1802019
# DATE DUE:   11/17
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
hash: hashmain.o htable.o
	g++ $(CCFLAGS) -o hash hashmain.o htable.o

# Rules to compile source code file to object code

hashmain.o: hashmain.cc hashmain.h htable.o
	g++ $(CCFLAGS) -c hashmain.cc

htable.o: htable.cc htable.h
	g++ $(CCFLAGS) -c htable.cc
	
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o hash
