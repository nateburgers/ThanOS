#pragma once

/* 64 Bit Real Numbers */
typedef integer64_t real64_t;
real64_t real64(integer32_t numerator, integer32_t denominator);
real64_t real64_add(real64_t x, real64_t y);
real64_t real64_subtract(real64_t x, real64_t y);
real64_t real64_multiply(real64_t x, real64_t y);
real64_t real64_divide(real64_t x, real64_t y);
integer32_t real64_to_integer32(real64_t x);
integer64_t real64_to_integer64(real64_t x);
