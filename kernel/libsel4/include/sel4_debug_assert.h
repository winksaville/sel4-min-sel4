/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */
/**
 * Declares macros and methods which are conditio unconditionally
 */
#ifndef __SEL4_DEBUG_ASSERT_H
#define __SEL4_DEBUG_ASSERT_H

#ifdef NDEBUG

/** NDEBUG is defined do nothing */
#define seL4_DebugAssert(expr) ((void)(0))

/** NDEBUG is defined do nothing */
#define seL4_DebugCompileTimeAssert(name, expr) ((void)(0))

#else // NDEBUG is not defined

#include <sel4_assert.h>

/**
 * NDEBUG is not defined invoke seL4_Assert(expr).
 */
#define seL4_DebugAssert(expr) seL4_Assert(expr)

/**
 * NDEBUG is not defined invoke seL4_CompileTimeAssert(expr).
 */
#define seL4_DebugCompileTimeAssert(name, expr) \
   seL4_CompileTimeAssert(name, expr)


#endif // NDEBUG

#endif // __SEL4_DEBUG_ASSERT_H
