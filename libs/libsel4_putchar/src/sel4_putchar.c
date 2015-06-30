/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#include <sel4_putchar.h>

#include <sel4/arch/syscalls.h>


/**
 * Output ch to a "terminal"
 */
void sel4_putchar(const char ch) {
#ifdef DEBUG
    seL4_DebugPutChar(ch);
#else
    // TODO: we need seL4_PutChar ????
#endif
}
