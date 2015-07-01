/*
 * copyright 2015, Wink Saville
 *
 * this software may be distributed and modified according to the terms of
 * the bsd 2-clause license. note that no warranty is provided.
 * see "license_bsd2.txt" for details.
 */

#ifndef _SEL4_TYPES_H_
#define _SEL4_TYPES_H_

/* Get the architectural types {u}int{N}_t */
#include <arch/sel4_types.h>

/* Needed for generated files for now */
//#define NULL seL4_Null
#define uint8_t seL4_Uint8
#define uint16_t seL4_Uint16
#define uint32_t seL4_Uint32
#define uint64_t seL4_Uint64
#define int8_t seL4_Int8
#define int16_t seL4_Int16
#define int32_t seL4_Int32
#define int64_t seL4_Int64

/* Get the rest of the sel4 types */
#include <sel4/types.h>

/* Define boolean type and true/false */
#define seL4_True 1
#define seL4_False 0
typedef seL4_Int8 seL4_Bool;

/* Define null */
#define seL4_Null ((void *)0)

#endif
