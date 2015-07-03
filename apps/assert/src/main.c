/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#include <sel4_types.h>
#include <sel4_assert.h>
#include <sel4_printf.h>

volatile seL4_Uint32 volatile0 = 0;

/**
 * No parameters are passed to main, the return
 * value is ignored and the program hangs.
 */
int main(void) {
    // Enable to test compile time errors
    //seL4_CompileTimeAssert(label0, 0 == 1);
    //seL4_DebugCompileTimeAssert(label1, 0 == 2);

    seL4_CompileTimeAssert(label0, 0 == 0);
    seL4_DebugCompileTimeAssert(label1, 0 == 0);

    // This succeeds
    seL4_Assert(volatile0 == 0);

    // By default this fails as NDEBUG is NOT defined.
    // To ignore the error use 'make menuconfig' and deselect
    // 'Toolchain Options -> build user level assertions ...'.
    seL4_DebugAssert(volatile0 == 1);

    // If the above statement does not fail then this always fails.
    seL4_Fail("Assert app done, NDEBUG is defined");

    return 0;
}