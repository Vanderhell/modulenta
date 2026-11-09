#include "../include/pc_poly_i32_monotonic_hint.h"
#include <assert.h>
#include <limits.h>

int main(void)
{
    pc_poly_i32_mono_result r = RM_POLY_I32_MONO_UNKNOWN;
    const int32_t increasing[] = {1, 0, 0};
    const int32_t decreasing[] = {-2, 3};
    const int32_t cubic_turn[] = {1, 0, -3, 0};
    const int32_t narrow_turn[] = {16384, -1536, 45, 0};
    const int32_t constant[] = {0, 0, 7};
    int32_t large[256];
    uint32_t i;
    assert(pc_poly_i32_monotonic_hint(increasing, 3u, 0, 2, &r));
    assert(r == RM_POLY_I32_MONO_NONDECREASING);
    assert(pc_poly_i32_monotonic_hint(decreasing, 2u, -100, 100, &r));
    assert(r == RM_POLY_I32_MONO_NONINCREASING);
    assert(pc_poly_i32_monotonic_hint(cubic_turn, 4u, -2, 2, &r));
    assert(r == RM_POLY_I32_MONO_UNKNOWN);
    assert(pc_poly_i32_monotonic_hint(narrow_turn, 4u, 0, 1, &r));
    assert(r == RM_POLY_I32_MONO_UNKNOWN);
    assert(pc_poly_i32_monotonic_hint(constant, 3u, INT32_MIN, INT32_MAX, &r));
    assert(r == RM_POLY_I32_MONO_CONSTANT);
    assert(pc_poly_i32_monotonic_hint(narrow_turn, 4u, 5, 5, &r));
    assert(r == RM_POLY_I32_MONO_CONSTANT);
    for (i = 0u; i < 256u; ++i) large[i] = INT32_MAX;
    r = RM_POLY_I32_MONO_UNKNOWN;
    assert(pc_poly_i32_monotonic_hint(large, 256u, INT32_MAX-1, INT32_MAX, &r));
    assert(r == RM_POLY_I32_MONO_UNKNOWN); /* checked derivative interval overflow */
    r = RM_POLY_I32_MONO_UNKNOWN;
    assert(!pc_poly_i32_monotonic_hint(large, 256u, INT32_MAX, INT32_MAX-1, &r));
    assert(r == RM_POLY_I32_MONO_UNKNOWN);
    assert(!pc_poly_i32_monotonic_hint(large, 256u, 0, 1, 0));
    r = RM_POLY_I32_MONO_CONSTANT;
    assert(!pc_poly_i32_monotonic_hint(large, 0u, 0, 1, &r));
    assert(r == RM_POLY_I32_MONO_CONSTANT);
    return 0;
}