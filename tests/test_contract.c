#include "pc_occupancy_max_burst_u32.h"

#include <stddef.h>

int main(void)
{
    const bool mixed[] = {false, true, true, false, true};
    const bool all_true[] = {true, true, true};
    uint32_t result = 91u;
    if (!pc_occupancy_max_burst_u32(mixed, 5u, &result) || result != 2u) return 1;
    if (!pc_occupancy_max_burst_u32(all_true, 3u, &result) || result != 3u) return 2;
    if (!pc_occupancy_max_burst_u32(mixed, 1u, &result) || result != 0u) return 3;
    result = 77u;
    if (pc_occupancy_max_burst_u32(mixed, 0u, &result) || result != 77u) return 4;
    if (pc_occupancy_max_burst_u32(NULL, 1u, &result) || result != 77u) return 5;
    if (pc_occupancy_max_burst_u32(mixed, 5u, NULL)) return 6;
    return 0;
}