/*
 * copyright 2015, Wink Saville
 *
 * this software may be distributed and modified according to the terms of
 * the bsd 2-clause license. note that no warranty is provided.
 * see "license_bsd2.txt" for details.
 */

#ifndef _SEL4_TYPES_H_
#define _SEL4_TYPES_H_

/* Get the architectural types seL4_{u}int{N} */
#include <arch/sel4_types.h>

/* Get the rest of the sel4 types */
#include <sel4/types.h>

/* Define boolean type and true/false */
#define seL4_True 1
#define seL4_False 0
typedef seL4_Int8 seL4_Bool;

/* Define null */
#define seL4_Null ((void *)0)

#include <sel4/arch/syscalls.h>
#include <sel4/arch/functions.h>

#include <sel4/invocation.h>
#include <interfaces/sel4_client.h>

#include <sel4_bootinfo.h>

#endif
