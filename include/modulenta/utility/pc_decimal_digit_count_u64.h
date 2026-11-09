#ifndef PRIMITIVECORE_DECIMAL_DIGIT_COUNT_U64_H
#define PRIMITIVECORE_DECIMAL_DIGIT_COUNT_U64_H
#include <stdint.h>

/* Return the number of base-10 digits; zero has one digit. */
uint8_t pc_decimal_digit_count_u64(uint64_t value);
#endif
