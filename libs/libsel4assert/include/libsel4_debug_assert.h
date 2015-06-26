/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#ifndef __LIBSEL4_DEBUG_ASSERT_H
#define __LIBSEL4_DEBUG_ASSERT_H

#ifdef DEBUG

#include <libsel4_assert.h>

#define libsel4_debug_fail(s) libsel4_fail(s, __FILE__, __LINE__, __func__)

#define libsel4_debug_assert(expr) libsel4_assert(expr)

#define libsel4_debug_compile_assert(name, expr) \
        libsel4_compile_assert(name, expr)

#else /* !DEBUG */

#include <libsel4_halt.h>

#define libsel4_debug_fail(s) libsel4_halt()

#define libsel4_debug_assert(expr)

#define libsel4_debug_compile_assert(name, expr)

#endif /* DEBUG */

#endif
