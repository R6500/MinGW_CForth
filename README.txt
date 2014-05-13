MinGW port of CForth
======================

Disclaimer
----------

This software is provided "as is," and you use the software at your own risk. The author make no warranties as to performance, merchantability, fitness for a particular purpose, or any other warranties whether expressed or implied. No oral or written communication from the author shall create a warranty. Under no circumstances shall the author be liable for direct, indirect, special, incidental, or consequential damages resulting from the use, misuse, or inability to use this software, even if the author has been advised of the possibility of such damages. 

What is CForth?
---------------

CForth is a Forth like engine written in C.
It was developed to be used in Microcontrollers but as the engine only needs a 32 bit system it can run on any 32 bit machine for which a GCC compiler exists.

CForth should build in any 32 bit GNU C Compiler.

I have compiled it in three systems by now:

 * Using MinGW in windows in an Eclipse IDE.

 * Using Yagarto Cross Compiler as part of the F3 Gizmo
   CForth port that runs on a STM32F3 Discovery board.

 * In Ubuntu Linux without any IDE.

There are two reasons why CForth exist:

1) To be able to develop the internal Forth like engine the 
   F3 Gizmo project without needing to flash the microcontroller.
   As CForth is system independent it can be developed on a PC.

2) To make easier to use the engine in different projects on
   different machines.



About the Base Port
-------------------

CForth must be associated to a port. The port provides the machine dependent code. At least the port must supply the console interaction functions and some constant definitions.

The base port is the minimum CForth port that works in any 32 bit PC that suports GNU tools. It has been used to develop CForth as this port don't need cross compilation.

Currently the Base Port has been checked to run on:

  * Windows 7 and Windows XP using MinGW 

  * Linux running Ubuntu 

CForth uses 32 bit pointers so running in a 64 bit machine could give unexpected results when using the CForth pointer operation words.
That includes all VARIABLE associated words like @ and !.
It doesn't affect VALUE associated words.


Source files
------------

CForth has been created to be implemented in several machines.
The code is modular. One part of the code is the same in any machine and the rest is a machine port.

There are three kind of source files:

CForth engine files
   They have the fm_ prefix.
   Those files are system independen and are always the same
   for a given CForth version.
   They provide the general base CForth Words and 
   the API functions that new port words use.

CForth port link files
   The have the fp_ prefix.
   Those files are system dependent but they must provide the same
   elements in any machine as they directly link with CFoth engine.

   Those files are:

        fp_config.h
        Gives general configuration for CForth
 
        fp_port.c and fp_port.h
        Gives the implementation of some machine dependent
        functionalities that CForth needs to run.

        fp_modules.h and fp_portDictionary.h
        Those files are used to register port specific words
        inside CForth.
        fp_modules.h list the header files that include the
        new words C functions.       
        fp_portDictionary.h gives registers each new word.
   
Port files
   They have no special prefix.
   Those files have no CForth dependences.




