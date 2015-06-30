/*
 * copyright 2015, Wink Saville
 *
 * this software may be distributed and modified according to the terms of
 * the bsd 2-clause license. note that no warranty is provided.
 * see "license_bsd2.txt" for details.
 */

#include <sel4_halt.h>
#include <sel4_printf.h>

/**
 * Invoked by macro sel4_fail in sel4_assert.h
 */
void _sel4_fail(const char* s, const char* file, unsigned int line,
	const char*  function) {
    sel4_printf("libsel4_fail called at %s:%u in function %s with '%s'\n",
        file, line, function, s);
    sel4_halt();
}

/**
 * Invoked by macro sel4_assert_fail in sel4_assert.h
 */
void _sel4_assert_fail(const char* assertion, const char* file, unsigned int line,
	const char*  function) {
    sel4_printf("Assertion failure '%s' at %s:%u in function %s\n",
       assertion, file, line, function);
    sel4_halt();
}
