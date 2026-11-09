#include "primitivecore/arithmetic/bounded/integer/pc_signed_width_i32.h"

uint8_t pc_signed_width_i32(int32_t value)
{
    uint32_t folded = value < 0 ? ~(uint32_t)value : (uint32_t)value;
    uint8_t width = 1u;
    while (folded != 0u) {
        ++width;
        folded >>= 1;
    }
    return width;
}
