#include "pc_lower_bound_i32.h"
#include <stddef.h>

bool rm_lower_bound_i32(const int32_t *sorted, size_t count, int32_t value,
                        size_t *out_index)
{
    size_t lo = 0u, hi = count;
    if (out_index == NULL || (sorted == NULL && count != 0u)) return false;
    while (lo < hi) {
        const size_t mid = lo + (hi - lo) / 2u;
        if (sorted[mid] < value) lo = mid + 1u;
        else hi = mid;
    }
    *out_index = lo;
    return true;
}