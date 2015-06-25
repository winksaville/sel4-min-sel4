# sel4-min-hw

An seL4 stree managed repository which uses libs/libsel4, tools/common,
tools/kbuild and app/min-hw. Does not use libc or any other library.

To make first copy a configuration such as
"cp apps/min-hw/configs/min-hw-x86-default .config" and
then "make" and finally "make simulate-min-hw-ia32".

The simulation runs qemu to exit qemu type "ctrl-a" then "x".
