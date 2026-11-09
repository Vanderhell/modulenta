#include "roundmath/sorted_gap_max_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int cmp_i32(const void *a, const void *b)
{
    const int32_t x = *(const int32_t *)a, y = *(const int32_t *)b;
    return (x > y) - (x < y);
}

static uint32_t reference(const int32_t *a, size_t n)
{
    size_t i;
    uint32_t best = 0u;
    for (i = 1u; i < n; ++i) {
        const uint32_t gap = (uint32_t)((int64_t)a[i] - (int64_t)a[i - 1u]);
        if (gap > best) best = gap;
    }
    return best;
}

int main(void)
{
    int32_t a[8];
    size_t n, limit, code, total = 0u;
    uint32_t out, state = UINT32_C(0x3de91a27);
    unsigned i, j;
    assert(pc_sorted_gap_max_i32(NULL, 0u, &out) && out == 0u);
    assert(pc_sorted_gap_max_i32(NULL, 0u, &out) && out == 0u);
    a[0] = INT32_MIN;
    assert(pc_sorted_gap_max_i32(a, 1u, &out) && out == 0u);
    assert(!pc_sorted_gap_max_i32(NULL, 1u, &out));
    assert(!pc_sorted_gap_max_i32(a, 1u, NULL));
    out = 91u;
    assert(!pc_sorted_gap_max_i32(NULL, 1u, &out) && out == 91u);
    a[0] = INT32_MIN; a[1] = 0; a[2] = INT32_MAX;
    assert(pc_sorted_gap_max_i32(a, 3u, &out) && out == UINT32_C(2147483648));
    a[0] = INT32_MIN; a[1] = INT32_MAX;
    assert(pc_sorted_gap_max_i32(a, 2u, &out) && out == UINT32_MAX);

    for (n = 0u; n <= 8u; ++n) {
        limit = 1u;
        for (j = 0u; j < n; ++j) limit *= 5u;
        for (code = 0u; code < limit; ++code) {
            size_t t = code;
            for (j = 0u; j < n; ++j) { a[j] = (int32_t)(t % 5u) - 2; t /= 5u; }
            qsort(a, n, sizeof a[0], cmp_i32);
            assert(pc_sorted_gap_max_i32(a, n, &out));
            assert(out == reference(a, n));
            ++total;
        }
    }
    for (i = 0u; i < 200000u; ++i) {
        for (j = 0u; j < 8u; ++j) {
            state ^= state << 13; state ^= state >> 17; state ^= state << 5;
            a[j] = (int32_t)state;
        }
        qsort(a, 8u, sizeof a[0], cmp_i32);
        assert(pc_sorted_gap_max_i32(a, 8u, &out));
        assert(out == reference(a, 8u));
    }
    printf("sorted max gap tests passed (%zu exhaustive cases, 200000 seeded)\n", total);
    return 0;
}
