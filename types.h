#pragma once
#include <stdbool.h>
#include <stdint.h>

#pragma mark - Booleans
typedef enum {
  Yes = 1,
  No = 0
} boolean_t;

#pragma mark - Characters
typedef char character_t;

#pragma mark - Natural Numbers
typedef uint8_t natural8_t;
typedef uint16_t natural16_t;
typedef uint32_t natural32_t;
typedef uint64_t natural64_t;
typedef natural32_t natural_t;

#pragma mark - Integers
typedef int8_t integer8_t;
typedef int16_t integer16_t;
typedef int32_t integer32_t;
typedef int64_t integer64_t;
typedef integer32_t integer_t;

#pragma mark - Pointers
typedef void any_t;
