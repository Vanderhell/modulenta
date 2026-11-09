#include "pc_binary_centroid_accum_i32.h"
#include <limits.h>
#include <stddef.h>

bool pc_binary_centroid_accum_i32(pc_binary_centroid_accum_i32_state *state,
                                  int32_t x, int32_t y)
{
    pc_binary_centroid_accum_i32_state next;
    int64_t dx = (int64_t)x;
    int64_t dy = (int64_t)y;
    if (state == NULL || state->count == UINT32_MAX) return false;
    next = *state;
    if ((dx > 0 && next.sum_x > INT64_MAX - dx) ||
        (dx < 0 && next.sum_x < INT64_MIN - dx) ||
        (dy > 0 && next.sum_y > INT64_MAX - dy) ||
        (dy < 0 && next.sum_y < INT64_MIN - dy)) return false;
    next.sum_x += dx;
    next.sum_y += dy;
    ++next.count;
    *state = next;
    return true;
}