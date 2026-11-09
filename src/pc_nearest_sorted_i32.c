#include "pc_nearest_sorted_i32.h"
#include "pc_lower_bound_i32.h"
#include <stddef.h>

static uint64_t distance_i32(int32_t a, int32_t b)
{
    const int64_t delta = (int64_t)a - (int64_t)b;
    return delta < 0 ? (uint64_t)(-delta) : (uint64_t)delta;
}

bool rm_nearest_sorted_i32(const int32_t *sorted, size_t count, int32_t value,
                           size_t *out_index)
{
    size_t at;
    if (sorted == NULL || count == 0u || out_index == NULL) return false;
    if (!rm_lower_bound_i32(sorted, count, value, &at)) return false;
    if (at < count && sorted[at] == value) {
        *out_index = at;
    } else if (at == 0u) {
        *out_index = 0u;
    } else if (at == count) {
        size_t first_last;
        if (!rm_lower_bound_i32(sorted, count, sorted[count - 1u], &first_last)) return false;
        *out_index = first_last;
    } else if (distance_i32(sorted[at - 1u], value) <= distance_i32(sorted[at], value)) {
        size_t first_left;
        if (!rm_lower_bound_i32(sorted, at, sorted[at - 1u], &first_left)) return false;
        *out_index = first_left;
    } else {
        *out_index = at;
    }
    return true;
}