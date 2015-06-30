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

/* Define boolean type and true/false */
#define sel4_true 1
#define sel4_false 0
typedef sel4_int8_t sel4_bool_t;

/* Define null */
#define sel4_null ((void *)0)

#endif
