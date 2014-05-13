//
// f p _ p o r t D i c t i o n a r y . h
//
// This file includes dictionary entries for the port functions
// The necessary includes to locate the functions must be
// referenced inside fport.h

// This line shows an example of one external definition
//   {"NAME","Description#(a)$",Function,value,flags},
//
// "NAME" is the word name
//
// "Description#(a)$" is the description ("#" marks start of second line)
//                                       ("$" is substituted by " -> "  )
//
// Function is the function that implements the word
// its prototype should be:
//      int32_t Function(ContextType *context,int32_t value)
//
// value will be set as the second parameter in the function calling
//
// flags can be:
//        DF_NI        Word cannot be executed in interactive mode
//
//        DF_NCOMPILE  Word cannot be compiled directly
//                     It won't probably be useful in port functions


{"QUIT","Exit from CForth",quitCForth,0,0},

