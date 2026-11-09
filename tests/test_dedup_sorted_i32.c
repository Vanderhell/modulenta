#include "roundmath/dedup_sorted_i32.h"
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

static size_t reference(const int32_t *a, size_t n, int32_t *out)
{
    size_t i, used = 0u;
    for (i = 0u; i < n; ++i) {
        if (used == 0u || out[used - 1u] != a[i]) out[used++] = a[i];
    }
    return used;
}

int main(void)
{
    int32_t a[8], expected[8];
    size_t n, limit, code, total = 0u, out;
    uint32_t state = UINT32_C(0x7a13b2e9);
    unsigned i, j;
    assert(pc_dedup_sorted_i32(NULL, 0u, &out) && out == 0u);
    assert(!pc_dedup_sorted_i32(NULL, 1u, &out));
    assert(!pc_dedup_sorted_i32(a, 0u, NULL));
    out = 73u;
    assert(!pc_dedup_sorted_i32(NULL, 1u, &out) && out == 73u);
    a[0] = INT32_MIN; a[1] = INT32_MIN; a[2] = -1; a[3] = 0;
    a[4] = INT32_MAX; a[5] = INT32_MAX;
    assert(pc_dedup_sorted_i32(a, 6u, &out) && out == 4u);
    assert(a[0] == INT32_MIN && a[1] == -1 && a[2] == 0 && a[3] == INT32_MAX);

    for (n = 0u; n <= 8u; ++n) {
        limit = 1u;
        for (j = 0u; j < n; ++j) limit *= 5u;
        for (code = 0u; code < limit; ++code) {
            size_t t = code, want;
            for (j = 0u; j < n; ++j) { a[j] = (int32_t)(t % 5u) - 2; t /= 5u; }
            qsort(a, n, sizeof a[0], cmp_i32);
            want = reference(a, n, expected);
            assert(pc_dedup_sorted_i32(a, n, &out) && out == want);
            for (j = 0u; j < out; ++j) assert(a[j] == expected[j]);
            ++total;
        }
    }
    for (i = 0u; i < 200000u; ++i) {
        size_t want;
        for (j = 0u; j < 8u; ++j) {
            state ^= state << 13; state ^= state >> 17; state ^= state << 5;
            a[j] = (int32_t)state;
        }
        qsort(a, 8u, sizeof a[0], cmp_i32);
        want = reference(a, 8u, expected);
        assert(pc_dedup_sorted_i32(a, 8u, &out) && out == want);
        for (j = 0u; j < out; ++j) assert(a[j] == expected[j]);
    }
    printf("sorted dedup tests passed (%zu exhaustive cases, 200000 seeded)\n", total);
    return 0;
}
