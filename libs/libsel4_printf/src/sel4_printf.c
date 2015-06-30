/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#include <sel4_types.h>
#include <sel4_vargs.h>
#include <sel4_putchar.h>
#include <sel4_printf.h>

static sel4_uint32_t
print_string(const char *s)
{
    sel4_uint32_t n;

    for (n = 0; *s; s++, n++) {
        sel4_putchar(*s);
    }

    return n;
}

static sel4_uint32_t
xdiv(sel4_uint32_t x, sel4_uint32_t denom)
{
    switch (denom) {
    case 16:
        return x / 16;
    case 10:
        return x / 10;
    default:
        return 0;
    }
}

static sel4_uint32_t
xmod(sel4_uint32_t x, sel4_uint32_t denom)
{
    switch (denom) {
    case 16:
        return x % 16;
    case 10:
        return x % 10;
    default:
        return 0;
    }
}

sel4_uint32_t
sel4_print_sel4_uint32_t(sel4_uint32_t x, sel4_uint32_t ui_base)
{
    char out[11];
    sel4_uint32_t i, j;
    sel4_uint32_t d;

    /*
     * Only base 10 and 16 supported for now. We want to avoid invoking the
     * compiler's support libraries through doing arbitrary divisions.
     */
    if (ui_base != 10 && ui_base != 16) {
        return 0;
    }

    if (x == 0) {
        sel4_putchar('0');
        return 1;
    }

    for (i = 0; x; x = xdiv(x, ui_base), i++) {
        d = xmod(x, ui_base);

        if (d >= 10) {
            out[i] = 'a' + d - 10;
        } else {
            out[i] = '0' + d;
        }
    }

    for (j = i; j > 0; j--) {
        sel4_putchar(out[j - 1]);
    }

    return i;
}


static sel4_uint32_t
print_sel4_uint64_t(sel4_uint64_t x, sel4_uint32_t ui_base)
{
    sel4_uint32_t upper, lower;
    sel4_uint32_t n = 0;
    sel4_uint32_t mask = 0xF0000000u;

    /* only implemented for hex, decimal is harder without 64 bit division */
    if (ui_base != 16) {
        return 0;
    }

    /* we can't do 64 bit division so break it up into two hex numbers */
    upper = (sel4_uint32_t) (x >> 32llu);
    lower = (sel4_uint32_t) x;

    /* print first 32 bits if they exist */
    if (upper > 0) {
        n += sel4_print_uint32_t(upper, ui_base);

        /* print leading 0s */
        while (!(mask & lower)) {
            sel4_putchar('0');
            n++;
            mask = mask >> 4;
        }
    }

    /* print last 32 bits */
    n += sel4_print_uint32_t(lower, ui_base);

    return n;
}


static int
vprintf(const char *format, sel4_va_list ap)
{
    sel4_uint32_t n;
    sel4_uint32_t formatting;

    if (!format) {
        return 0;
    }

    n = 0;
    formatting = 0;
    while (*format) {
        if (formatting) {
            switch (*format) {
            case '%':
                sel4_putchar('%');
                n++;
                format++;
                break;

            case 'd': {
                int x = sel4_va_arg(ap, int);

                if (x < 0) {
                    sel4_putchar('-');
                    n++;
                    x = -x;
                }

                n += sel4_print_sel4_uint32_t((sel4_uint32_t)x, 10);
                format++;
                break;
            }

            case 'u':
                n += sel4_print_sel4_uint32_t(sel4_va_arg(ap, sel4_uint32_t), 10);
                format++;
                break;

            case 'x':
                n += sel4_print_sel4_uint32_t(sel4_va_arg(ap, sel4_uint32_t), 16);
                format++;
                break;

            case 'p': {
                sel4_uint32_t p = sel4_va_arg(ap, sel4_uint32_t);
                if (p == 0) {
                    n += print_string("(nil)");
                } else {
                    n += print_string("0x");
                    n += sel4_print_sel4_uint32_t(p, 16);
                }
                format++;
                break;
            }

            case 's':
                n += print_string(sel4_va_arg(ap, char *));
                format++;
                break;

            case 'l':
		// Support llx only
                if (*(format + 1) == 'l' && *(format + 2) == 'x') {
                    sel4_uint64_t arg = sel4_va_arg(ap, sel4_uintt64_t);
                    n += print_sel4_uint64_t(arg, 16);
                    format += 3;
                }
                break;
            default:
                format++;
                break;
            }

            formatting = 0;
        } else {
            switch (*format) {
            case '%':
                formatting = 1;
                format++;
                break;

            default:
                sel4_putchar(*format);
                n++;
                format++;
                break;
            }
        }
    }

    return n;
}

/**
 * Print a formated string to a "terminal". This supports a
 * subset of the typical libc printf:
 *   - %% ::= prints a percent
 *   - %d ::= prints a positive or negative long base 10
 *   - %u ::= prints an sel4_uint32_t base 10
 *   - %x ::= prints a sel4_uint32_t base 16
 *   - %p ::= prints a sel4_uint32_t assuming its a pointer base 16 with 0x prepended
 *   - %s ::= prints a string
 *   - %llx ::= prints a sel4_uint32_t long base 16
 */
sel4_uint32_t
sel4_printf(const char *format, ...)
{
    sel4_va_list args;
    sel4_uint32_t i;

    sel4_va_start(args, format);
    i = vprintf(format, args);
    sel4_va_end(args);
    return i;
}
