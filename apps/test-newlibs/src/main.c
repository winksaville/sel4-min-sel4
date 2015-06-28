/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#include <libsel4_printf.h>
#include <libsel4_debug_printf.h>
#include <libsel4_halt.h>
#include <libsel4_assert.h>
#include <libsel4_debug_assert.h>
#include <libsel4_putchar.h>

/**
 * No parameters are passed to main, the return
 * value is ignored and the program hangs.
 */
int main(void) {
    libsel4_putchar('H');
    libsel4_putchar('\n');
    libsel4_printf("Hello, World\n");
    libsel4_debug_printf("Hello, World: debug printf\n");

    //libsel4_debug_assert(0 == 1);
    //libsel4_assert(1 == 2);
    libsel4_debug_assert(0 == 0);
    libsel4_assert(1 == 1);

    libsel4_printf("Halting...\n");
    libsel4_halt();

    return 0;
}
