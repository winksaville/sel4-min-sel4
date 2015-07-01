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
 * Invoked by macro seL4_fail in seL4_assert.h
 */
void _seL4_Fail(const char* s, const char* file, unsigned int line,
	const char*  function) {
    seL4_Printf("seL4_fail called at %s:%u in function %s with '%s'\n",
        file, line, function, s);
    seL4_Halt();
}

/**
 * Invoked by macro seL4_assert_fail in seL4_assert.h
 */
void _seL4_AssertFail(const char* assertion, const char* file, unsigned int line,
	const char*  function) {
    seL4_Printf("Assertion failure '%s' at %s:%u in function %s\n",
       assertion, file, line, function);
    seL4_Halt();
}
