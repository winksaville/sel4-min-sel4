/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

/**
 * Declares macros and methods for sel4 specific assert and fail.
 *
 * These are unconditional, there are conditional versions of
 * sel4_debug_assert and sel4_debug_compile_asssert available
 * by including sel4_debug_assert.h.
 */

#ifndef __SEL4_ASSERT_H
#define __SEL4_ASSERT_H

/**
 * Hidden function, use the macro seL4_Fail.
 */
void _seL4_Fail(const char*  str, const char* file, unsigned int line,
	const char*  function);

/**
 * Hidden funtion, use the macro seL4_Assert.
 */
void _seL4_AssertFail( const char* assertion, const char* file, unsigned int line,
	const char* function);

/**
 * If expr evaluates to false _seL4_Fail is called with the
 * expr as a string plus the file, line and function.
 */
#define seL4_Fail(s) _seL4_Fail(s, __FILE__, __LINE__, __func__)

/**
 * If expr evaluates to false _seL4_AssertFail is called with the
 * expr as a string plus the file, line and function.
 */
#define seL4_Assert(expr) \
    do { if (!(expr)) { _seL4_AssertFail(#expr, __FILE__, __LINE__, __FUNCTION__); } } while(0)

/**
 * An assert that will define a unique typedef of an array of 1
 * on success and attempt to create it with a -1 on failure. A
 * negative size will cause a compile time error.
 */
#define seL4_CompileTimeAssert(name, expr) \
    typedef int __seL4_CompileTimeAssertFailed_##name[(expr) ? 1 : -1]  __attribute__((unused))

#endif
