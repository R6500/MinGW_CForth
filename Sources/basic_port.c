/**************************************************
 *
 *  b a s i c _ p o r t . c
 *
 *  File with the basic port specific words and data
 *
 *************************************************/

#include <stdlib.h>

#include "fp_config.h"         // Main configuration file
#include "fp_port.h"           // Main port definitions
#include "fm_main.h"           // Main forth header file
#include "basic_port.h"

/******* COMMAND FUNCTIONS *************************************/

// Quit from the basic port
int32_t quitCForth(ContextType *context,int32_t value)
 {
 UNUSED(context); // So that the compiler doesn't complain
 UNUSED(value);   // So that the compiler doesn't complain

 // Call the exit function
 exit(0);

 // We won't return from this point as we called exit
 return 0;
 }
