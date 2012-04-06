#ifndef __LIB_KERNEL_FIXEDPOINT_H
#define __LIB_KERNEL_FIXEDPOINT_H

/* Basic kernel fixed point 17.14 arithmatic routines. */
#include <stdint.h>

/* Floating point type definition. */
typedef int64_t fp_t;

/* Conversion routines. */
fp_t int_to_fp (int32_t i);
int32_t fp_to_int_floor (fp_t);
int32_t fp_to_int_nearest (fp_t);

/* Basic arithmatic operations. */
fp_t add_fp (fp_t x, fp_t y);
fp_t sub_fp (fp_t x, fp_t y);
fp_t mul_fp (fp_t x, fp_t y);
fp_t div_fp (fp_t x, fp_t y);

fp_t add_fp_int (fp_t x, int32_t y);
fp_t sub_fp_int (fp_t x, int32_t y);
fp_t mul_fp_int (fp_t x, int32_t y);
fp_t div_fp_int (fp_t x, int32_t y);

void test_fixed_point_routines (void);

#endif /* lib/kernel/fixedpoint.h */
