#include "pc_state_onehot_encode_u32.h"
#include <stddef.h>

bool rm_state_onehot_encode_u32(uint8_t bit_index, uint32_t *onehot_value)
{
    if (onehot_value == NULL || bit_index > 31u) return false;
    *onehot_value = UINT32_C(1) << bit_index;
    return true;
}