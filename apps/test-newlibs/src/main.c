/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#include <sel4_types.h>
#include <sel4_printf.h>
#include <sel4_debug_printf.h>
#include <sel4_halt.h>
#include <sel4_assert.h>
#include <sel4_debug_assert.h>
#include <sel4_putchar.h>
#include <sel4_benchmark.h>
#include <sel4_bootinfo.h>

/**
 * No parameters are passed to main, the return
 * value is ignored and the program hangs.
 */
int main(void) {

    /* Manually test these runtime errors, enable one at a time */
    //seL4_Fail("failing");
    //seL4_Assert(0 == 1);
    //seL4_DebugAssert(1 == 2);

    /* Manually test these compile time asserts */
    //seL4_CompileTimeAssert(CTA_Test1, 2 == 3);
    //seL4_DebugCompileTimeAssert(DCTA_Test1, 3 == 4);

    seL4_BenchmarkResetLog();

    seL4_PutChar('H');
    seL4_PutChar('\n');
    seL4_Printf("Hello, World\n");
    seL4_DebugPrintf("Hello, World: via seL4_DebugDrintf\n");

    seL4_Printf("%=%%\n");
    seL4_Printf("str=%s\n", "string");
    seL4_Printf("int=%d\n", -123);
    seL4_Printf("uint=%u\n", -1);
    seL4_Printf("uint=0x%x\n", 0xfedcba98);
    seL4_Printf("uint64=0x%llx\n", 0xfedcba9876543210ll);
    seL4_Printf("&main=%p\n", &main);

    seL4_BenchmarkDumpFullLog();

    seL4_Assert(0 == 0);
    seL4_DebugAssert(0 == 0);
    seL4_CompileTimeAssert(CTA_Test2, 1 == 1);
    seL4_DebugCompileTimeAssert(DCTA_Test2, 2 == 2);
    seL4_Bool b = seL4_True;
    seL4_Assert(b != seL4_False);
  
    seL4_Int8 i8 = 1;
    seL4_Assert(i8 == 1);
    seL4_Assert(sizeof(i8) == 1);
    seL4_Int16 i16 = 2;
    seL4_Assert(i16 == 2);
    seL4_Assert(sizeof(i16) == 2);
    seL4_Int32 i32 = 3;
    seL4_Assert(i32 == 3);
    seL4_Assert(sizeof(i32) == 4);
    seL4_Int64 i64 = 4;
    seL4_Assert(i64 == 4);
    seL4_Assert(sizeof(i64) == 8);

    seL4_Uint8 u8 = 1;
    seL4_Assert(u8 == 1);
    seL4_Assert(sizeof(u8) == 1);
    seL4_Uint16 u16 = 2;
    seL4_Assert(u16 == 2);
    seL4_Assert(sizeof(u16) == 2);
    seL4_Uint32 u32 = 3;
    seL4_Assert(u32 == 3);
    seL4_Assert(sizeof(u32) == 4);
    seL4_Uint64 u64 = 4;
    seL4_Assert(u64 == 4);
    seL4_Assert(sizeof(u64) == 8);

    seL4_Uint8 *p = seL4_Null;
    seL4_Assert(p == seL4_Null);

    seL4_BootInfo *bi = seL4_GetBootInfo();
    seL4_Printf("bi=%p\n", bi);
    seL4_Printf("bi->nodeId=%d\n", bi->nodeID);

    seL4_Printf("Halting...\n");
    seL4_Halt();

    return 0;
}
