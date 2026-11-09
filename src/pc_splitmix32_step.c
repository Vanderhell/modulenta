#include "pc_splitmix32_step.h"

static uint32_t mix32(uint32_t value)
{
    value = (value ^ (value >> 16u)) * UINT32_C(0x21F0AAAD);
    value = (value ^ (value >> 15u)) * UINT32_C(0x735A2D97);
    return value ^ (value >> 15u);
}

rm_splitmix32_step_result rm_splitmix32_step(uint32_t state)
{
    state += UINT32_C(0x9E3779B9);
    const rm_splitmix32_step_result result = {state, mix32(state)};
    return result;
}