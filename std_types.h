/*
******************************************************
this file is to configure the data types for the system 
It defines the data types (compiler specific)
*********************************************
*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char BOOLEAN;

typedef unsigned char U8_t;
typedef signed char S8_t;

typedef unsigned int U16_t;
typedef signed int S16_t;

typedef unsigned long U32_t;
typedef signed long S32_t;

typedef float FP32;
typedef double FP64;

typedef int MAINRETURN_t;

#define BYTE S8_t
#define UBYTE U8_t

#define WORD S16_t
#define UWORD U16_t

#define LONG S32_t
#define ULONG U32_t

#define TRUE 1
#define FALSE 0

#endif
