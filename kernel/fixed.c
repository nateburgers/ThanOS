#include "fixed.h"

static const integer64_t Real64Point = 1<<32;

inline real64_t __attribute__((always_inline))
real64(integer32_t numerator, integer32_t denominator)
{
  return numerator * Real64Point / denominator;
}

inline real64_t __attribute__((always_inline))
real64_add(real64_t x, real64_t y)
{
  return x + y;
}

inline real64_t __attribute__((always_inline))
real64_subtract(real64_t x, real64_t y)
{
  return x - y;
}

inline real64_t __attribute__((always_inline))
real64_multiply(real64_t x, real64_t y)
{
  return ((integer64_t) x) * y / Real64Point;
}

inline real64_t __attribute__((always_inline))
real64_divide(real64_t x, real64_t y)
{
  return ((integer64_t) x) * Real64Point / y;
}

inline integer32_t __attribute__((always_inline))
real64_to_integer32(real64_t x)
{
  return (integer32_t) real64_to_integer64(x);
}

inline integer64_t __attribute__((always_inline))
real64_to_integer64(real64_t x)
{
  if (x >= 0)
    {
      return (x + Real64Point / 2) / Real64Point;
    }
  else
    {
      return (x - Real64Point / 2) / Real64Point;
    }
}
