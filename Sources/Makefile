# MinGW Makefile
# Project: Forth
# Version 1.0 (17/3/2014)
#
# History:
#     v1.0 First version

# Paths for this project
# ./        Location for all files
# ./build   Location for build files


# General definitions
CC=gcc
CFLAGS=-c -Wall -O2 -g $(INCLUDE) 
#LDFLAGS=-lpthread 

# Build directory
# This directory is hard-coded in the rules section
# don't change if you don't change also the $(BUILDIR): rule
BUILDIR=./build

# Program specific definitions

# SOURCES must include relative paths to each C source
# from the location of the Makefile
# It is recommeded to locate all this files in a src
# directory below the directory where makefile is located
SOURCES=fp_port.c \
        fm_test.c \
        fm_main.c \
        fm_stack.c \
        fm_register.c \
        fm_program.c \
        fm_debug.c \
        fm_screen.c \
        fm_branch.c \
        fm_threads.c \
        basic_port.c \
        main.c

# CHECK_INCLUDES include header files that force recompilation
CHECK_INCLUDES=fp_port.h \
               fp_portDictionary.h \
               fm_test.h \
               fm_stack.h \
               fm_register.h \
               fm_program.h \
               fm_debug.h \
               fm_screen.h \
               fm_branch.h \
               fm_threads.h \
               basic_port.h \
               fm_main.h

# EXECUTABLE define the name of the final executable
# In will be generated on the location where this
# Makefile is located
EXECUTABLE=cforth.exe


# Object files to be generated
# They will be located in the same place as the source files
OBJECTS=$(SOURCES:.c=.o)

# Include file paths include general "C" include location
# and the "include" directory below the location where
# this makefile is located
INCLUDE=\
	-I. \
	-Iinclude

# Rules to objects
_OBJECTS = $(patsubst %,$(BUILDIR)/%,$(OBJECTS))

# Make rules

all: $(SOURCES) $(EXECUTABLE) $(BUILDDIR)

clean:
	rm -rf $(BUILDIR)/*.o $(PWD)/$(EXECUTABLE)
	
$(BUILDIR): 
	mkdir .\build	
	
$(EXECUTABLE): $(_OBJECTS)
	$(CC) $(LDFLAGS) $(_OBJECTS) -o $@

$(BUILDIR)/%.o: %.c $(CHECK_INCLUDES) $(BUILDIR)
	$(CC) $(CFLAGS) $< -o $@





