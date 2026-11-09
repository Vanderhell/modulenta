#include "../include/pc_table_spacing_max_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t rng = 0x856C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}
static int32_t from_bits(uint32_t bits)
{
    return bits <= (uint32_t)INT32_MAX ? (int32_t)bits
                                      : (int32_t)((int64_t)bits - 4294967296LL);
}
static int compare_i32(const void *left, const void *right)
{
    int32_t a = *(const int32_t *)left, b = *(const int32_t *)right;
    return (a > b) - (a < b);
}
static bool oracle(const int32_t *a, size_t n, uint32_t *out)
{
    size_t i;
    uint64_t max = 0u;
    if (n < 2u) return false;
    for (i = 1u; i < n; ++i) {
        int64_t gap = (int64_t)a[i] - (int64_t)a[i - 1u];
        if (gap < 0) return false;
        if ((uint64_t)gap > max) max = (uint64_t)gap;
    }
    *out = (uint32_t)max;
    return true;
}

int main(void)
{
    int32_t a[128];
    uint32_t got, expected, tested = 0u;
    size_t i, j, n;
    for (n = 2u; n <= 6u; ++n) {
        uint64_t cases = 1u, code;
        for (i = 0u; i < n; ++i) cases *= 7u;
        for (code = 0u; code < cases; ++code) {
            uint64_t x = code;
            bool valid;
            for (i = 0u; i < n; ++i) { a[i] = (int32_t)(x % 7u) - 3; x /= 7u; }
            valid = oracle(a, n, &expected);
            got = 999u;
            assert(pc_table_spacing_max_i32(a, n, &got) == valid);
            if (valid) assert(got == expected); else assert(got == 999u);
            ++tested;
        }
    }
    for (i = 0u; i < 100000u; ++i) {
        size_t len = next_u32() % 128u + 2u;
        for (j = 0u; j < len; ++j) a[j] = from_bits(next_u32());
        qsort(a, len, sizeof(a[0]), compare_i32);
        assert(oracle(a, len, &expected));
        assert(pc_table_spacing_max_i32(a, len, &got) && got == expected);
    }
    for (i = 0u; i < 100000u; ++i) {
        size_t len = next_u32() % 128u + 2u;
        bool valid;
        for (j = 0u; j < len; ++j) a[j] = from_bits(next_u32());
        valid = oracle(a, len, &expected);
        got = 777u;
        assert(pc_table_spacing_max_i32(a, len, &got) == valid);
        if (valid) assert(got == expected); else assert(got == 777u);
    }
    {
        static const int32_t full[] = {INT32_MIN, INT32_MAX};
        static const int32_t dup[] = {-1, -1, 0};
        static const int32_t bad[] = {INT32_MIN, 0, -1};
        assert(pc_table_spacing_max_i32(full, 2u, &got) && got == UINT32_MAX);
        assert(pc_table_spacing_max_i32(dup, 3u, &got) && got == 1u);
        got = 777u;
        assert(!pc_table_spacing_max_i32(bad, 3u, &got) && got == 777u);
        assert(!pc_table_spacing_max_i32(full, 1u, &got) && got == 777u);
        assert(!pc_table_spacing_max_i32(NULL, 2u, &got) && got == 777u);
        assert(!pc_table_spacing_max_i32(full, 2u, NULL));
    }
    printf("maximum spacing tests passed: exhaustive=%lu seeded=200000\n", (unsigned long)tested);
    return 0;
}
