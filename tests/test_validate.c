#include "../include/pc_table_validate_monotonic_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng = 0x854C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}

static bool oracle(const int32_t *a, size_t n)
{
    size_t i, j;
    for (i = 0u; i < n; ++i)
        for (j = i + 1u; j < n; ++j)
            if (a[i] >= a[j]) return false;
    return true;
}

int main(void)
{
    int32_t a[128];
    uint32_t encoded, tested = 0u;
    size_t n, i;
    for (n = 0u; n <= 8u; ++n) {
        uint32_t cases = 1u;
        for (i = 0u; i < n; ++i) cases *= 5u;
        for (encoded = 0u; encoded < cases; ++encoded) {
            uint32_t x = encoded;
            for (i = 0u; i < n; ++i) { a[i] = (int32_t)(x % 5u) - 2; x /= 5u; }
            assert(pc_table_validate_monotonic_i32(n == 0u ? NULL : a, n) == oracle(a, n));
            ++tested;
        }
    }
    for (i = 0u; i < 100000u; ++i) {
        size_t j;
        n = next_u32() % 129u;
        for (j = 0u; j < n; ++j) a[j] = (int32_t)next_u32();
        assert(pc_table_validate_monotonic_i32(n == 0u ? NULL : a, n) == oracle(a, n));
    }
    {
        static const int32_t strict[] = {INT32_MIN, -1, 0, INT32_MAX};
        static const int32_t duplicate[] = {INT32_MIN, 0, 0, INT32_MAX};
        static const int32_t descending[] = {INT32_MIN, INT32_MAX, INT32_MAX - 1};
        assert(pc_table_validate_monotonic_i32(strict, 4u));
        assert(!pc_table_validate_monotonic_i32(duplicate, 4u));
        assert(!pc_table_validate_monotonic_i32(descending, 3u));
    }
    assert(pc_table_validate_monotonic_i32(NULL, 0u));
    assert(!pc_table_validate_monotonic_i32(NULL, 1u));
    printf("strict monotonic tests passed: exhaustive=%lu seeded=100000\n", (unsigned long)tested);
    return 0;
}