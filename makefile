################################################################################
#
#       Makefile for TEMPLATE, should work for gcc and clang
#
################################################################################

#edit finder, locate commonly eddited places >>edit<<

############################################################################
# Macros
############################################################################

#name of exe                                                                edit
EXE = SolveMate
#Compiler name (default should be gcc)
CC =g++
#src code base directory
SRC =./src/
#directory to compile to. if needed to be changed.
DIR = ./$(CC)/
#object files. (files between compile and link)	                            edit
OBJ =$(DIR)$(EXE).o 

#NOTE TO SELF, templated impl cant be compiled ahead of time. (duh.. )

############################################################################
# Overide flags
############################################################################
#   allows for adding flags instead of overwriting them.

#compiler flags,
override CFLAGS+= -g -O -Wall -Wextra -ansi -pedantic -pthread -std=c++17
#Linker flags,
override LFLAGS+= -lpthread

#input for test against
TIN = output.txt
#output file for test.
TOUT = my$(TIN)

# self allows you to force a recompile by adding a dependency of the makefile.
SELF =

############################################################################
# Helpers
###########################################################################

#output silencer, will only print errors
ifndef VERBOSE
.SILENT:
endif

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
	# use the rest as arguments for "run"
	RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
	# ...and turn them into do-nothing targets
	$(eval $(RUN_ARGS):;@:)
endif

# If the first argument is "valg"...
ifeq (valg,$(firstword $(MAKECMDGOALS)))
	# use the rest as arguments for "valg"
	RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
	# ...and turn them into do-nothing targets
	$(eval $(RUN_ARGS):;@:)
endif

#NOTE: if run args are getopt you must type '--' before.

############################################################################
# Main Make.
############################################################################

# links the program, Default recipy.
$(DIR)$(EXE) : $(OBJ) $(SELF)
	$(CC) $(OBJ) -o $(DIR)$(EXE) $(LFLAGS)
	-$(MAKE) #tablen #tablen isnt relivent anymore

# compiles a .o file for the "main" file.
$(DIR)$(EXE).o : $(SRC)$(EXE).cpp $(SELF)
	$(CC) $(CFLAGS) -c $(SRC)$(EXE).cpp  -o $(DIR)$(EXE).o

#...	                                                                    edit

# compiles a .o for graph.cpp                                               edit
#$(DIR)graph.o : $(SRC)graph.cpp $(SRC)graph.h $(SELF)
#	$(CC) $(CFLAGS) -c $(SRC)graph.cpp -o $(DIR)graph.o

# compiles a .o file for any template                                       edit
#$(DIR)TEMPLATE.o : $(SRC)TEMPLATE.c $(SRC)TEMPLATE.h $(SELF)
#	$(CC) $(CFLAGS) -c $(SRC)TEMPLATE.c -o $(DIR)TEMPLATE.o

############################################################################
# Commands recipys.
############################################################################

# Cleans the directory.
clean :
	rm $(DIR)$(EXE) $(OBJ)

# throws out old code and forces a recompile and link.
new :
	-$(MAKE) clean
	-$(MAKE)

# runs the exe from your desired directory.
.PHONY: run
run :
	$(DIR)$(EXE) $(RUN_ARGS)

#forces recompile and link then runs.
newRun :
	-$(MAKE) new
	-$(MAKE) run

# Checks Character langth of all eddited code,
# MUST add all relivent cpp files.                                          edit
tablen :
	tablen $(EXE).c

# creats output from run and compares it to test.
diff :
	-$(MAKE) run > $(DIR)$(TOUT)
	diff $(DIR)$(TOUT) $(TIN) --strip-trailing-cr

# runs doctor memory on code for windows memory testing
drmem:
	-$(MAKE) clean
	-$(MAKE) CFLAGS+=-g
	drmemory -batch -no_summary -- $(DIR)$(EXE)

# runs valgrind on code.
.PHONY: run
valg:
	-$(MAKE) clean
	-$(MAKE) CFLAGS+=-g
	valgrind -q --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes $(DIR)$(EXE) $(RUN_ARGS)
