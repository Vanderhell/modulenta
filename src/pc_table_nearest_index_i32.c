#include "pc_table_nearest_index_i32.h"

static uint32_t distance_i32(int32_t a, int32_t b)
{
    return a >= b ? (uint32_t)a - (uint32_t)b
                  : (uint32_t)b - (uint32_t)a;
}

bool rm_table_nearest_index_i32(const int32_t *values, size_t count,
                                int32_t query, size_t *index)
{
    size_t i, best_index;
    uint32_t best_distance;
    if (values == NULL || count == 0u || index == NULL) return false;
    best_index = 0u;
    best_distance = distance_i32(values[0], query);
    for (i = 1u; i < count; ++i) {
        uint32_t distance = distance_i32(values[i], query);
        if (distance < best_distance) {
            best_distance = distance;
            best_index = i;
        }
    }
    *index = best_index;
    return true;
}