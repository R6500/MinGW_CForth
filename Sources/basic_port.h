/**************************************************
 *
 *  b a s i c _ p o r t . h
 *
 *  File with the basic port specific words and data
 *
 *************************************************/

#ifndef _BASIC_MODULE
#define _BASIC_MODULE

// Basic port version
#define BASIC_VERSION  "1.0"
#define BASIC_DATE     "27/4/2014"

// Command function prototypes

int32_t quitCForth(ContextType *context,int32_t value);

#endif //_BASIC_MODULE
