/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

/**
 * Declares macros and methods for libsel4 specific assert and fail.
 *
 * These are unconditional, there are conditional versions of 
 * libsel4_debug_assert and libsel4_debug_compile_asssert available
 * by including libsel4_debug_assert.h.
 */

#ifndef __LIBSEL4_ASSERT_H
#define __LIBSEL4_ASSERT_H

/**
 * Hidden funtion, use the macro libsel4_fail.
 */
void _libsel4_fail(const char*  str, const char* file, unsigned int line,
	const char*  function);

/**
 * Hidden funtion, use the macro libsel4_assert.
 */
void _libsel4_assert_fail( const char* assertion, const char* file, unsigned int line,
	const char* function);

/**
 * If expr evaluates to false _libsel4_assert_fail is called with the
 * expr as a string plus the file, line and function.
 */ 
#define libsel4_fail(s) _libsel4_fail(s, __FILE__, __LINE__, __func__)

/**
 * If expr evaluates to false _libsel4_assert_fail is called with the
 * expr as a string plus the file, line and function.
 */ 
#define libsel4_assert(expr) \
    do { if (!(expr)) { _libsel4_assert_fail(#expr, __FILE__, __LINE__, __FUNCTION__); } } while(0)

/**
 * An assert that will define a unique typedef of an array of 1
 * on success and attempt to create it with a -1 on failure. A
 * negative size will cause a compile time error.
 */
#define libsel4_compile_assert(name, expr) \
    typedef int __libsel4_cassert_failed_##name[(expr) ? 1 : -1];

#endif
