/**************************************************
 *
 *  f p _ p o r t . h
 *
 *  PORT for MinGW
 *
 * General port include for the forth project
 *
 * PORT FILE : This file is implementation dependent
 *
 * This file provides includes for general definitions
 * that can be machine dependent.
 *
 * It also includes definitions for structures that are
 * also machine dependent
 *
 *************************************************/

#ifndef _FP_PORT_INCLUDE
#define _FP_PORT_INCLUDE

// Definitions for datatypes ------------------------------

// int8_t int16_t int32_t uint8_t uint16_t uint32_t
#include <stdint.h>

// Standard I/O
#include <stdio.h>

// Port console definitions -------------------------------

// Definition for line break
// Default line break
//      BREAK_0    (CR+LF)
//      BREAK_1    (CR)
//      BREAK_2    (LF)
#define BREAK_DEFAULT BREAK_0

// Definition to know if we have console
// We have always console in MinGW
#define NO_CONSOLE     0

// Definition for printf function
#define consolePrintf(...)     printf(  __VA_ARGS__ )

// Port element for program memory ------------------------

// This structure will be added to the program memory
// that will be loaded at start-up when the user dictionary
// is loaded.

typedef struct
 {
 uint32_t vref4096;              // Internal Vref*4096 (For STM32F3)
 }PortSave;

// Thread priority levels --------------------------------

// Priority limits
#define MAX_PRIO     10   // Dummy values as we have
#define MIN_PRIO    -10   // not implemented threads in MinGW

// PAD Definitions ---------------------------------------

// Address of the PAD
#define PAD_ADDRESS  ((uint32_t)(pad))

// PAD size. Must be multiple of 4
#define PAD_SIZE     2048

// Extern pad definition
extern int32_t pad[PAD_SIZE/4];

// MACROS ------------------------------------------------

// The following macro should give a non zero value (true)
// if all current tasks should abort
// It should normaly be associated to a hardware line

#define PORT_ABORT  (0)   // Not used yet

// The following macros implement thread list locking
// As  there are no threads implemented no locking is needed

#define LOCK_TLIST      // Empty macro
#define UNLOCK_TLIST    // Empty macro

// Function prototypes -----------------------------------

// Console char function definitions
 int32_t consoleGetChar(void);
 void consolePutChar(int32_t value);

// Function, if any that will initialize the port section
void portSaveInit(PortSave *pointer);

// Functions to save and load the dictionary
int32_t saveUserDictionary();
int32_t loadUserDictionary();

// Thread function
int32_t portThreadCreate(int32_t nth, void *pointer);

// Show port specific limits
void portShowLimits(void);

// Callback check
int32_t isAnyCallback(void);

#endif //_FP_PORT_INCLUDE

