/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#include <libsel4_halt.h>
#include <libsel4_printf.h>

/**
 * Invoked by macro libsel4_fail in libsel4_assert.h
 */
void _libsel4_fail(const char* s, const char* file, unsigned int line,
	const char*  function) {
    libsel4_printf("libsel4_fail called at %s:%u in function %s with '%s'\n",
        file, line, function, s);
    libsel4_halt();
}

/**
 * Invoked by macro libsel4_assert_fail in libsel4_assert.h
 */
void _libsel4_assert_fail(const char* assertion, const char* file, unsigned int line,
	const char*  function) {
    libsel4_printf("Assertion failure '%s' at %s:%u in function %s\n",
       assertion, file, line, function);
    libsel4_halt();
}
