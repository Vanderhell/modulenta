#include "pc_decimal_digit_count_u64.h"

uint8_t pc_decimal_digit_count_u64(uint64_t value)
{
    uint8_t count = 1u;
    while (value >= 10u) {
        value /= 10u;
        ++count;
    }
    return count;
}