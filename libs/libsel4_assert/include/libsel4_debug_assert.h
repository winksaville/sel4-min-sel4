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
#ifndef __LIBSEL4_DEBUG_ASSERT_H
#define __LIBSEL4_DEBUG_ASSERT_H

#ifdef NDEBUG

/** NOP assert as DEBUG is not defined */
#define libsel4_debug_assert(expr) ((void)(0))

/** NOP compile time assert as DEBUG is not defined */
#define libsel4_debug_compile_assert(name, expr) ((void)(0))

#else

#include <libsel4_assert.h>

/**
 * If DEBUG is defined this is libsel4_assert(expr) and if expr
 * evaluates to false _libsel4_assert_fail is called with the
 * expr as a string plus the file, line and function.
 */ 
#define libsel4_debug_assert(expr) libsel4_assert(expr)

/**
 * If DEBUG is defined this is libsel4_assert(expr) and if expr
 * evaluates to false _libsel4_assert_fail is called with the
 * expr as a string plus the file, line and function.
 */ 
#define libsel4_debug_compile_assert(name, expr) \
   libsel4_compile_assert(name, expr)


#endif

#endif
