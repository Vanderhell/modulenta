#include "roundmath/unique_sorted_count_i32.h"
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

static size_t reference(const int32_t *a, size_t n)
{
    size_t i, out = 0u;
    for (i = 0u; i < n; ++i) {
        size_t j;
        for (j = 0u; j < i && a[j] != a[i]; ++j) { }
        if (j == i) ++out;
    }
    return out;
}

int main(void)
{
    int32_t a[8], sorted[8];
    size_t out, n, code, limit, total = 0u;
    uint32_t state = UINT32_C(0x21a7c39d);
    unsigned i, j;
    assert(pc_unique_sorted_count_i32(NULL, 0u, &out) && out == 0u);
    assert(!pc_unique_sorted_count_i32(NULL, 1u, &out));
    assert(!pc_unique_sorted_count_i32(a, 0u, NULL));
    out = 77u;
    assert(!pc_unique_sorted_count_i32(NULL, 1u, &out) && out == 77u);
    a[0] = INT32_MIN; a[1] = INT32_MIN; a[2] = -1; a[3] = 0;
    a[4] = INT32_MAX; a[5] = INT32_MAX;
    assert(pc_unique_sorted_count_i32(a, 6u, &out) && out == 4u);

    /* Exhaust every length <= 8 over five values; sort each input first. */
    for (n = 0u; n <= 8u; ++n) {
        limit = 1u;
        for (j = 0u; j < n; ++j) limit *= 5u;
        for (code = 0u; code < limit; ++code) {
            size_t t = code;
            for (j = 0u; j < n; ++j) { a[j] = (int32_t)(t % 5u) - 2; t /= 5u; }
            qsort(a, n, sizeof a[0], cmp_i32);
            assert(pc_unique_sorted_count_i32(a, n, &out));
            assert(out == reference(a, n));
            ++total;
        }
    }

    for (i = 0u; i < 200000u; ++i) {
        for (j = 0u; j < 8u; ++j) {
            state ^= state << 13; state ^= state >> 17; state ^= state << 5;
            a[j] = (int32_t)state;
        }
        for (j = 0u; j < 8u; ++j) sorted[j] = a[j];
        qsort(sorted, 8u, sizeof sorted[0], cmp_i32);
        assert(pc_unique_sorted_count_i32(sorted, 8u, &out));
        assert(out == reference(sorted, 8u));
    }
    printf("unique sorted count tests passed (%zu exhaustive cases, 200000 seeded)\n", total);
    return 0;
}
