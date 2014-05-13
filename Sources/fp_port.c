/**************************************************
 *
 *  f p _ p o r t . c
 *
 *  PORT for MinGW
 *
 * General port source file for the forth project
 *
 * PORT FILE : This file is implementation dependent
 *
 *
 *************************************************/

#include "fp_config.h"  // Main configuration file
#include "fp_port.h"    // This module header file
#include "fm_main.h"    // Main forth header file
#include "fm_program.h" // Program header file
#include "fm_screen.h"  // Screen header file

// PAD storage
int32_t pad[PAD_SIZE/4];

// External definitions

extern UserDictionary  UDict;
extern uint32_t MainFlags;

/*************** PUBLIC FUNCTIONS ********************/

// Console character functions -------------------------

// Get one character from the console
// Block if there is none
int32_t consoleGetChar(void)
 {
 return getchar();   // Buffered with echo (stdio.h)
 //return getch();   // Unbuffered without echo (conio.h)
 }

// Put one character to the console
// Block if there if buffer is full
void consolePutChar(int32_t value)
 {
 putchar(value);   // Stdio function
 //putch(value);   // Conio function
 }

// Persistent data functions -----------------------------

// fport.h includes a definition for a PortSave typedef
// This will include data that will be saved with the
// rest of the forth program data
// portSaveInit initialized this structure
void portSaveInit(PortSave *pointer)
 {
 // Not used in the MinGW PORT
 }

// Save and Load functions ------------------------------

// Functions to save all the data contained in the
// UserDictionary typedef contained in program.c

// In MinGW port a file will be used and the magic
// word won't be used

// Save user dictionary to "userDict.bin"
// Returns 0 if it works ok
int32_t saveUserDictionary()
 {
 FILE *f;

 // Open to write
 f=fopen("userDict.bin","wb");

 // Abort in case of error
 if (!f) return 1;

 // Write data in one big chunk
 if (fwrite(&UDict,sizeof(UserDictionary),1,f)<1)
	            return 2;

 // Close the file
 fclose(f);

 return 0;
 }

int32_t loadUserDictionary()
 {
 FILE *f;

 // Open to read
 f=fopen("userDict.bin","rb");

 // Exit if not found
 if (!f) return 1;

 // Load data in one big chunk
 if (fread(&UDict,sizeof(UserDictionary),1,f)<1)
          {
	      // Restore to default
	      programInit();
	      return 2;
          }

 // Indicate that data was loaded
 MainFlags|=MFLAG_LOADED;

 // Close the file
 fclose(f);

 return 0;
 }

// Thread functions ------------------------------

// Dummy portThreadCreate
// As there are no real thread no real execution will be done
// In the same way the thread cannot be eliminated
//
// Return 0 if OK
int32_t portThreadCreate(int32_t nth, void *pointer)
 {
 consolePrintf("Dummy portThreadCreate%s",BREAK);
 consolePrintf("Don't create any real thread%s",BREAK);

 return 0; // OK
 }

// Show limits -----------------------------------

// Current MinGW port has no specific limits
// They return 0
void portShowLimits(void)
 {
 // Does nothing
 }

// Callback check --------------------------------

// Returns non zero if there is any registered callback function
int32_t isAnyCallback(void)
 {
 // Dummy 0 return as the MinGW port doesn't use any callback
 return 0;
 }

