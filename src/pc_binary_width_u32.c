#include "pc_binary_width_u32.h"

uint8_t pc_binary_width_u32(uint32_t value)
{
    uint8_t width = 0u;
    while (value != 0u) {
        ++width;
        value >>= 1;
    }
    return width;
}