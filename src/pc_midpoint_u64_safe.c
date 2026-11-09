#include "pc_midpoint_u64_safe.h"

uint64_t pc_midpoint_u64_safe(uint64_t a, uint64_t b)
{
    return (a & b) + ((a ^ b) >> 1u);
}