# sel4-min-sel4

An seL4 stree managed repository which uses libs/libsel4, tools/common,
tools/kbuild and does not use libc.

To make, first copy a configuration such as
"cp configs/all-app-conf .config" and
then "make" and finally one or more files such as
"make simulate app=test-newlibs".

The simulation runs qemu, to exit qemu type "ctrl-a" then "x".
