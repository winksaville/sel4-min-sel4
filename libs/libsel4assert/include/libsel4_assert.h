/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#ifndef __LIBSEL4_ASSERT_H
#define __LIBSEL4_ASSERT_H

void _libsel4_fail(const char*  str, const char* file, unsigned int line,
	const char*  function);

#define libsel4_fail(s) _libsel4_fail(s, __FILE__, __LINE__, __func__)

void _libsel4_assert_fail( const char* assertion, const char* file, unsigned int line,
	const char* function);

#define libsel4_assert(expr) \
    if (!(expr)) { _libsel4_assert_fail(#expr, __FILE__, __LINE__, __FUNCTION__) }

/* Create an assert that will trigger a compile error if it fails. */
#define libsel4_compile_assert(name, expr) \
        typedef int __libsel4_compile_assert_failed_##name[(expr) ? 1 : -1];

#else /* !DEBUG */

#include <halt.h>

#define fail(s) halt()

#define assert(expr)

#define compile_assert(name, expr)

#endif /* DEBUG */

#endif
