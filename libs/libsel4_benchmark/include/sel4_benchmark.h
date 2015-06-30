/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef SEL4_BENCHMARK
#define SEL4_BENCHMARK

#include <autoconf.h>

#ifdef CONFIG_BENCHMARK

/* entire ipc buffer except tag register (word 0) */
#define MAX_IPC_BUFFER (1024 - 1)

#include <sel4_types.h>
#include <sel4_printf.h>
#include <sel4/arch/syscalls.h>

static inline void
seL4_BenchmarkDumpFullLog()
{
    sel4_uint32_t potential_size = seL4_BenchmarkLogSize();

    for (sel4_uint32_t j = 0; j < potential_size; j += MAX_IPC_BUFFER) {
        sel4_uint32_t chunk = potential_size - j;
        sel4_uint32_t requested = chunk > MAX_IPC_BUFFER ? MAX_IPC_BUFFER : chunk;
        sel4_uint32_t recorded = seL4_BenchmarkDumpLog(j, requested);
        for (sel4_uint32_t i = 0; i < recorded; i++) {
            sel4_printf("%u\t", seL4_GetMR(i));
        }
        sel4_printf("\n");
        /* we filled the log buffer */
        if (requested != recorded) {
            sel4_printf("Dumped %u of %u potential logs\n", j + recorded, potential_size);
            return;
        }
    }

    /* logged amount was smaller than log buffer */
    sel4_printf("Dumped entire log, size %u\n", potential_size);
}

#else // CONFIG_BENCHMARK is not defined

#pragma message "In " __FILE__ " CONFIG_BENCHMARK is not defined. Select 'seL4 Kernel' -> 'seL4 System Parameters' -> 'Adds a log buffer to the kernel ...'"

#endif // CONFIG_BENCHMARK

#endif // SEL4_BENCHMARK

