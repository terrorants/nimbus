/*-
 * Copyright (c) 1990, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)vsprintf.c  8.1 (Berkeley) 6/4/93";
#endif /* LIBC_SCCS and not lint */

#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define USE_CUSTOM_FORMATTERS 1
//#define USE_PRINTF_HOOKS  1

typedef struct {
  char* pbuf;
  int rem;
  int printed;
} printf_state_t;

#if USE_PRINTF_HOOKS
typedef void (*xsnprintf_hook_cb)(char ch, va_list ap, printf_state_t* state);

#define MAX_HOOKS 4
static xsnprintf_hook_cb hooks[MAX_HOOKS];
static int hooks_count = 0;

int xsnprintf_add_hook(xsnprintf_hook_cb hook)
{
  if (hooks_count == MAX_HOOKS) {
    return -1;
  }
  hooks[hooks_count++] = hook;
  return 0;
}

int xsnprintf_remove_hook(xsnprintf_hook_cb hook)
{
  for (int i = 0; i < hooks_count; ++i) {
    if (hooks[i] == hook) {
      for (int j = i + 1; j < hooks_count; ++i) {
        hooks[j - 1] = hooks[j];
      }
      --hooks_count;
      return 0;
    }
  }
  return -1;
}

void xsnprintf_hook_print(const char* p, int len, printf_state_t* state)
{
  state->printed = 1;
  while (len-- > 0) {
    if (state->rem > 1) {
      *(state->pbuf)++ = *p++;
      state->rem--;
    }
  }
}

static int do_printf_hooks(char ch, va_list ap, char** pbuf, int* rem)
{
  for (int i = 0; i < hooks_count; ++i) {
    printf_state_t state = { *pbuf, *rem, 0 };
    (*hooks[i])(ch, ap, &state);
    if (state.printed) {
      *pbuf = state.pbuf;
      int hook_ret = (*rem - state.rem);
      *rem = state.rem;
      return hook_ret;
    }
  }
  return -1;
}
#endif


typedef unsigned int u_int;
typedef unsigned long u_long;

/*
 * Flags used during conversion.
 */
#define LADJUST   0x004   /* left adjustment */
#define ZEROPAD   0x080   /* zero (as opposed to blank) pad */
#define SIZET   0x400   /* size_t */
#define PTRDIFFT  0x800   /* ptrdiff_t */
#define INTMAXT   0x1000    /* intmax_t */
#define CHARINT   0x2000    /* print char using int format */

/*
 * Macros for converting digits to letters and vice versa
 */
#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n)  ((n) + '0')

#define BUF 32

/*
 * Convert an unsigned long to ASCII for printf purposes, returning
 * a pointer to the first character of the string representation.
 * Octal numbers can be forced to have a leading zero; hex numbers
 * use the given digits.
 */
static char*
__ultoa(u_long val, char* endp, int base, int octzero, const int upper)
{
  char* cp = endp;
  long sval;

  /*
   * Handle the three cases separately, in the hope of getting
   * better/faster code.
   */
  switch (base) {
    case 10:
      if (val < 10) { /* many numbers are 1 digit */
        *--cp = to_char(val);
        return (cp);
      }
      /*
       * On many machines, unsigned arithmetic is harder than
       * signed arithmetic, so we do at most one unsigned mod and
       * divide; this is sufficient to reduce the range of
       * the incoming value to where signed arithmetic works.
       */
      if (val > LONG_MAX) {
        *--cp = to_char(val % 10);
        sval = val / 10;
      } else {
        sval = val;
      }
      do {
        *--cp = to_char(sval % 10);
        sval /= 10;
      } while (sval != 0);
      break;

    case 8:
      do {
        *--cp = to_char(val & 7);
        val >>= 3;
      } while (val);
      if (octzero && *cp != '0') {
        *--cp = '0';
      }
      break;

    case 16:
      do {
        sval = val & 15;
        *--cp = sval <= 9 ? to_char(sval) : sval - 10 + (upper ? 'A' : 'a');
        val >>= 4;
      } while (val);
      break;
  }
  return (cp);
}

int xvsnprintf(char* __restrict b0, size_t b0len, const char* __restrict fmt0, va_list ap)
{
  char* fmt;    /* format string */
  int ch;     /* character from fmt */
  int n;      /* handy integer (short term usage) */
  char* b;    /* output pointer */
  int rem;    /* space remaining */
  char* cp;   /* handy char pointer (short term usage) */
  int flags;    /* flags as above */
  int ret;    /* return value accumulator */
  int width;    /* width from format (%8d), or 0 */
  int prec;   /* precision from format; <0 for N/A */
  char sign;    /* sign prefix (' ', '+', '-', or \0) */

  u_long  ulval;    /* integer arguments %[diouxX] */
  int base;   /* base for [diouxX] conversion */
  int dprec;    /* a copy of prec if [diouxX], 0 otherwise */
  int realsz;   /* field size expanded by dprec, sign, etc */
  int size;   /* size of converted field or string */
  int prsize;             /* max size of printed field */
  int upper;        /* Is it %X conversion */
  char buf[BUF];    /* buffer with space for digits of uintmax_t */
  char ox[2];   /* space for 0x; ox[1] is either x, X, or \0 */

#define PRINT(ptr, len) { \
    char *__p = (ptr); \
    int __l = (len); \
    while(__l-- > 0) \
      if(rem > 1) { \
        *b++ = *__p++;  \
        rem--;  \
      } \
  }
#define PAD(len, with) { \
    int __l = (len); \
    while(__l-- > 0) \
      if(rem > 1) { \
        *b++ = (with);  \
        rem--;  \
      } \
  }

  /* Get the next argument */
#define GETARG(type) va_arg(ap, type)
  /* Signed and unsigned argument extraction methods. */
#define SARG() GETARG(int)
#define UARG() GETARG(u_int)

  fmt = (char*)fmt0;
  b = (char*)b0;
  rem = b0len;
  upper = 0;
  ret = 0;
  size = 0;

  /*
   * Scan the format for conversions (`%' character).
   */
  for (;;) {
    for (cp = fmt; (ch = *fmt) != '\0' && ch != '%'; fmt++)
      /* void */;
    if ((n = fmt - cp) != 0) {
      if ((unsigned)ret + n > INT_MAX) {
        ret = EOF;
        goto error;
      }
      PRINT(cp, n);
      ret += n;
    }
    if (ch == '\0') {
      goto done;
    }
    fmt++;    /* skip over '%' */

    flags = 0;
    dprec = 0;
    width = 0;
    prec = -1;
    sign = '\0';
    ox[1] = '\0';

rflag:
    ch = *fmt++;

#if USE_PRINTF_HOOKS
    int hook_ret = do_printf_hooks(ch, ap, &b, &rem);
    if (hook_ret != -1) {
      ret += hook_ret;
      continue;
    }
#endif

reswitch:
    switch (ch) {
      case ' ':
        /*-
         * ``If the space and + flags both appear, the space
         * flag will be ignored.''
         *  -- ANSI X3J11
         */
        if (!sign) {
          sign = ' ';
        }
        goto rflag;
      case '*':
        /*-
         * ``A negative field width argument is taken as a
         * - flag followed by a positive field width.''
         *  -- ANSI X3J11
         * They don't exclude field widths read from args.
         */
        width = GETARG(int);
        if (width >= 0) {
          goto rflag;
        }
        width = -width;
        /* FALLTHROUGH */
      case '-':
        flags |= LADJUST;
        goto rflag;
      case '+':
        sign = '+';
        goto rflag;
      case '.':
        if ((ch = *fmt++) == '*') {
          prec = GETARG(int);
          goto rflag;
        }
        prec = 0;
        while (is_digit(ch)) {
          prec = 10 * prec + to_digit(ch);
          ch = *fmt++;
        }
        goto reswitch;
      case '0':
        /*-
         * ``Note that 0 is taken as a flag, not as the
         * beginning of a field width.''
         *  -- ANSI X3J11
         */
        flags |= ZEROPAD;
        goto rflag;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        n = 0;
        do {
          n = 10 * n + to_digit(ch);
          ch = *fmt++;
        } while (is_digit(ch));
        width = n;
        goto reswitch;
      case 'h':
      case 'l':
        goto rflag;
      case 'c':
        *(cp = buf) = GETARG(int);
        size = 1;
        sign = '\0';
        break;
      case 'd':
      case 'i':
        ulval = SARG();
        if ((long)ulval < 0) {
          ulval = -ulval;
          sign = '-';
        }
        base = 10;
        goto number;
        /*FALLTHROUGH*/
      case 'o':
        ulval = UARG();
        base = 8;
        goto nosign;
      case 'p':
        /*-
         * ``The argument shall be a pointer to void.  The
         * value of the pointer is converted to a sequence
         * of printable characters, in an implementation-
         * defined manner.''
         *  -- ANSI X3J11
         */
        ulval = (uintptr_t)GETARG(void*);
        base = 16;
        ox[1] = 'x';
        goto nosign;
      case 's':
        if ((cp = GETARG(char*)) == NULL) {
          cp = "(null)";
        }
        size = (prec >= 0) ? strnlen(cp, prec) : strlen(cp);
        sign = '\0';
        break;
      case 'u':
        ulval = UARG();
        base = 10;
        goto nosign;
      case 'X':
        upper = 1;
        /*FALLTHROUGH*/
      case 'x':
        ulval = UARG();
        base = 16;

        /* unsigned conversions */
nosign:
        sign = '\0';
        /*-
         * ``... diouXx conversions ... if a precision is
         * specified, the 0 flag will be ignored.''
         *  -- ANSI X3J11
         * except for %#.0o and zero value
         */
number:
        if ((dprec = prec) >= 0) {
          flags &= ~ZEROPAD;
        }

        /*-
         * ``The result of converting a zero value with an
         * explicit precision of zero is no characters.''
         *  -- ANSI X3J11
         *
         * ``The C Standard is clear enough as is.  The call
         * printf("%#.0o", 0) should print 0.''
         *  -- Defect Report #151
         */
        cp = buf + sizeof(buf);
        if (ulval != 0 || prec != 0) {
          cp = __ultoa(ulval, cp, base, 0, upper);
        }
        size = buf + sizeof(buf) - cp;
        break;

#if USE_CUSTOM_FORMATTERS
        typedef struct {
          int32_t sec;
          int16_t msec;
        } fmt_oi_time_t;

      case '!': {   /* OI status code -- treat it as int for now */
        ulval = SARG();
        if ((long)ulval < 0) {
          ulval = -ulval;
          sign = '-';
        }
        base = 10;
        goto number;
      }

      case 'T': {   /* format time */
        fmt_oi_time_t* time = (fmt_oi_time_t*)GETARG(void*);
        if (time == NULL) {
          cp = "(null)";
          PRINT(cp, 6);
          ret += 6;
        } else {
          cp = buf + sizeof(buf);
          ulval = (time->sec & 0x1FFF);
          cp = __ultoa(ulval, cp, 10, 0, 1);
          size = buf + sizeof(buf) - cp;
          PRINT(cp, size);
          ret += size;
          ulval = time->msec;
          *(cp = buf) = '.';
          PRINT(cp, 1);
          ret += 1;
          if (ulval < 10) {
            cp = "00";
            PRINT(cp, 2);
            ret += 2;
          } else if (ulval < 100) {
            cp = "0";
            PRINT(cp, 1);
            ret += 1;
          }
          cp = buf + sizeof(buf);
          cp = __ultoa(ulval, cp, 10, 0, 1);
          size = buf + sizeof(buf) - cp;
          PRINT(cp, size);
          ret += size;
        }
        continue;
      }
      break;

      case 'B':   /* format boolean as TRUE or FALSE */
        ulval = UARG();
        if (ulval) {
          cp = "TRUE";
          PRINT(cp, 4);
          ret += 4;
        } else {
          cp = "FALSE";
          PRINT(cp, 5);
          ret += 5;
        }
        continue;
      break;

      case ':':   /* format BD_ADDR as hex string */
      case ';':   /* format link key as hex string */
      case '@': {   /* format data, len as hex string */
        uint8_t* data = (uint8_t*)GETARG(void*);
        size = 0;
        char sep = '\0';
        switch (ch) {
          case '@':
            ulval = UARG();
            size = (ulval & 0xFFFF);
            sep = ' ';
            break;
          case ':':
            size = 6;
            sep = ':';
            break;
          case ';':
            size = 16;
            break;
        }
        if (data == NULL) {
          cp = "(null)";
          PRINT(cp, 6);
          ret += 6;
        } else {
          int i;
          for (i = 0; i < size; ++i) {
            if (sep != '\0' && i > 0) {
              *(cp = buf) = sep;
              PRINT(buf, 1);
              ret += 1;
            }
            cp = buf + sizeof(buf);
            ulval = data[i];
            cp = __ultoa(ulval, cp, 16, 0, 1);
            if (ulval < 16) {
              (*--cp) = '0';
            }
            PRINT(cp, 2);
            ret += 2;
          }
        }
        continue;
      }
      break;
#endif
      default:  /* "%?" prints ?, unless ? is NUL */
        if (ch == '\0') {
          goto done;
        }
        /* pretend it was %c with argument ch */
        cp = buf;
        *cp = ch;
        size = 1;
        sign = '\0';
        break;
    }

    /*
     * All reasonable formats wind up here.  At this point, `cp'
     * points to a string which (if not flags&LADJUST) should be
     * padded out to `width' places.  If flags&ZEROPAD, it should
     * first be prefixed by any sign or other prefix; otherwise,
     * it should be blank padded before the prefix is emitted.
     * After any left-hand padding and prefixing, emit zeroes
     * required by a decimal [diouxX] precision, then print the
     * string proper, then emit zeroes required by any leftover
     * floating precision; finally, if LADJUST, pad with blanks.
     *
     * Compute actual size, so we know how much to pad.
     * size excludes decimal prec; realsz includes it.
     */
    realsz = dprec > size ? dprec : size;
    if (sign) {
      realsz++;
    }
    if (ox[1]) {
      realsz += 2;
    }

    prsize = width > realsz ? width : realsz;
    if ((unsigned)ret + prsize > INT_MAX) {
      ret = EOF;
      goto error;
    }

    /* right-adjusting blank padding */
    if ((flags & (LADJUST | ZEROPAD)) == 0) {
      PAD(width - realsz, ' ');
    }

    /* prefix */
    if (sign) {
      PRINT(&sign, 1);
    }

    if (ox[1]) {  /* ox[1] is either x, X, or \0 */
      ox[0] = '0';
      PRINT(ox, 2);
    }

    /* right-adjusting zero padding */
    if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD) {
      PAD(width - realsz, '0');
    }

    /* the string or number proper */
    /* leading zeroes from decimal precision */
    PAD(dprec - size, '0');
    PRINT(cp, size);

    /* left-adjusting padding (always blank) */
    if (flags & LADJUST) {
      PAD(width - realsz, ' ');
    }

    /* finally, adjust ret */
    ret += prsize;

  }
done:
error:
  *b = 0;
  return (ret);
}
#if 0
int xsnprintf(char* __restrict str, size_t n, char const* __restrict fmt, ...)
{
  int ret;
  va_list ap;
  va_start(ap, fmt);
  ret = xvsnprintf(str, n, fmt, ap);
  va_end(ap);
  return (ret);
}

int xvsnprintf_append(char* buffer, size_t size, int* offset, const char* format, va_list args)
{
  int off = (offset != NULL ? *offset : 0);
  int avail = (int)size - off;
  int ret = xvsnprintf(&buffer[off], avail, format, args);
  if (ret > 0 && offset != NULL) {
    int count = MIN(ret, avail);
    (*offset) += count;
  }
  return ret;
}

int xsnprintf_append(char* buffer, size_t size, int* offset, const char* format, ...)
{
  if (format == NULL) {
    return 0;
  }
  va_list args;
  va_start(args, format);
  int ret = xvsnprintf_append(buffer, size, offset, format, args);
  va_end(args);
  return ret;
}
#endif
