#include "pc_round_robin_next_u32.h"
#include <stddef.h>

bool pc_round_robin_next_u32(uint32_t current, uint32_t count,
                             uint32_t *next)
{
    if (next == NULL || count == 0u || current >= count) return false;
    *next = current == count - 1u ? 0u : current + 1u;
    return true;
}