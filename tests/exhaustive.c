#include "nearest_endpoint_u32.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t oracle(uint32_t value, uint32_t a, uint32_t b)
{
    uint32_t low = a < b ? a : b;
    uint32_t high = a < b ? b : a;
    uint64_t dl = value >= low ? (uint64_t)value - low : (uint64_t)low - value;
    uint64_t dh = value >= high ? (uint64_t)value - high : (uint64_t)high - value;
    return dl <= dh ? low : high;
}

int main(void)
{
    uint32_t value, a, b;
    for (value = 0; value < 256; ++value)
        for (a = 0; a < 256; ++a)
            for (b = 0; b < 256; ++b)
                if (pc_nearest_endpoint_u32(value, a, b) != oracle(value, a, b)) return 1;
    puts("PASS: all 16,777,216 uint8 triples");
    return 0;
}
