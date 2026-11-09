#include "pc_lcg_jump_u32.h"

uint32_t rm_lcg_jump_u32(uint32_t state, uint32_t multiplier, uint32_t increment, uint32_t steps)
{
    uint32_t accumulated_multiplier = 1u;
    uint32_t accumulated_increment = 0u;
    uint32_t current_multiplier = multiplier;
    uint32_t current_increment = increment;
    while (steps != 0u) {
        if ((steps & 1u) != 0u) {
            accumulated_multiplier *= current_multiplier;
            accumulated_increment = accumulated_increment * current_multiplier + current_increment;
        }
        current_increment *= current_multiplier + 1u;
        current_multiplier *= current_multiplier;
        steps >>= 1u;
    }
    return accumulated_multiplier * state + accumulated_increment;
}