#include "pc_state_onehot_index_u32.h"
#include <stddef.h>

bool pc_state_onehot_index_u32(uint32_t value, uint8_t *bit_index)
{
    uint8_t index = 0u;
    if (bit_index == NULL || value == 0u || (value & (value - 1u)) != 0u) {
        return false;
    }
    while ((value & 1u) == 0u) {
        value >>= 1u;
        ++index;
    }
    *bit_index = index;
    return true;
}