#include "pc_monotonic_search_i32.h"
#include <stddef.h>

bool pc_monotonic_search_i32(int32_t lo, int32_t hi,
                             pc_monotonic_predicate_i32 predicate,
                             void *context, bool *found, int32_t *first_true)
{
    int64_t left, right;
    if (predicate == NULL || found == NULL || first_true == NULL || lo > hi) return false;
    left = lo;
    right = (int64_t)hi + 1;
    while (left < right) {
        const int64_t mid = left + (right - left) / 2;
        if (predicate((int32_t)mid, context)) right = mid;
        else left = mid + 1;
    }
    if (left <= hi) {
        *first_true = (int32_t)left;
        *found = true;
    } else {
        *found = false;
    }
    return true;
}