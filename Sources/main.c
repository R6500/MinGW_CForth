/***********************************************************************
 *  
 * m a i n . c
 *
 * PORT for MinGW
 *
 * Main file for the Forth project
 *
 * Version 1.0 (17/3/2014)
 * 
 * PORT FILE : This file is implementation dependent
 *
 * This file just need to call the forth interpreter
 * calling:
 *
 *  forthInit function in fmain.c
 *  forthMain function in fmain.c
 *
 ***********************************************************************/

#include <stdlib.h>

#include "fp_config.h"         // Main configuration file
#include "fp_port.h"           // Main port definitions
#include "fm_main.h"           // Main forth header file
#include "fm_test.h"           // Forth test functions header file
#include "basic_port.h"

// External variables
extern uint32_t VerboseLevel;  // Verbose level in fmain.c

int main()
 {
 // Show datatypes (testing only) -- Works Ok
 // Not for release version
 //ftestShowTypes();

 forthInit();

 // Remove echo from verbose level in windows command console
 // Don't need to be removed in ansicon console
 // This is a port characteristic
 MainContext.VerboseLevel&=(~VBIT_ECHO);

 // Dump the start of memory;
 //ftestDumpMem();

 // Show start message
 printf("\nBasic bare bones CForth port\n");
 printf("Version %s (%s)\n",BASIC_VERSION,BASIC_DATE);
 printf("You can exit with the QUIT word\n\n");

 // Start the CForth engine
 forthMain();

 // forthMain should not return
 printf("\nMain end. We should not arrive here\n\n");
 return 0;
 }




