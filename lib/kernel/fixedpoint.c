#include "fixedpoint.h"
#include "debug.h"

/* FIXED_POINT = 2 ^ 14 */
static const int32_t FIXED_POINT = (0x1 << 20);

/* Conversion routines. */
fp_t int_to_fp (int32_t i)
{
  return i * FIXED_POINT;
}

int32_t fp_to_int_floor (fp_t f)
{
  return f / FIXED_POINT;
}

int32_t fp_to_int_nearest (fp_t f)
{
  if (f > 0)
    return (f + (FIXED_POINT / 2)) / FIXED_POINT;
  else
    return (f - (FIXED_POINT / 2)) / FIXED_POINT;
}

/* Basic arithmatic operations. */
fp_t add_fp (fp_t x, fp_t y)
{
  return x + y;
}

fp_t sub_fp (fp_t x, fp_t y)
{
  return x - y;
}

fp_t mul_fp (fp_t x, fp_t y)
{
  return (fp_t) (
    (((int64_t) x) * y) / FIXED_POINT
  );
}
fp_t div_fp (fp_t x, fp_t y)
{
  return (fp_t) (
    (((int64_t) x) * FIXED_POINT) / y
  );
}

fp_t add_fp_int (fp_t f, int32_t i)
{
  return f + int_to_fp (i);
}

fp_t sub_fp_int (fp_t f, int32_t i)
{
  return f - int_to_fp (i);
}

fp_t sub_int_fp (int32_t i, fp_t f)
{
  return int_to_fp (i) - f;
}

fp_t mul_fp_int (fp_t f, int32_t i)
{
  return f * i;
}

fp_t div_fp_int (fp_t f, int32_t i)
{
  return f / i;
}

int32_t div_int_fp (int32_t i, fp_t f)
{
  return int_to_fp (i) / f;
}

void test_fixed_point_routines (void)
{
  fp_t fp_99 = int_to_fp(99);
  fp_t fp_0p06 = 983;
  fp_t fp_1p06 = add_fp_int (fp_0p06, 1);
  fp_t coeff = div_fp (fp_0p06, fp_1p06);
  fp_t fp_res = mul_fp (coeff, fp_99);

  /* Tests. */
  ASSERT (fp_99 == 1622016);
  ASSERT (fp_1p06 == 17367);
  ASSERT (coeff == 927);
  ASSERT (fp_res == 91773);

  /* Some other tests. */
  ASSERT (int_to_fp (0) == 0);
  ASSERT (int_to_fp (1) != 0);
  ASSERT (add_fp_int (0, 1) == int_to_fp (1));
}
