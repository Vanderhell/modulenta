#include "pc_state_onehot_check_u32.h"

bool rm_state_onehot_check_u32(uint32_t value)
{
    return value != 0u && (value & (value - 1u)) == 0u;
}