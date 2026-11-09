#include "pc_table_nearest_index_i32.h"
#include "pc_nearest_sorted_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng = 0x860C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}
static int32_t from_bits(uint32_t bits)
{
    return bits <= (uint32_t)INT32_MAX ? (int32_t)bits
                                      : (int32_t)((int64_t)bits - 4294967296LL);
}
static size_t oracle(const int32_t *values, size_t count, int32_t query)
{
    size_t i, best = 0u;
    uint64_t best_dist = UINT64_MAX;
    for (i = 0u; i < count; ++i) {
        int64_t delta = (int64_t)values[i] - query;
        uint64_t distance = (uint64_t)(delta < 0 ? -delta : delta);
        if (distance < best_dist) { best_dist = distance; best = i; }
    }
    return best;
}

int main(void)
{
    int32_t values[5];
    size_t got;
    uint32_t tested = 0u;
    size_t n, i;
    for (n = 1u; n <= 5u; ++n) {
        uint32_t cases = 1u, code;
        for (i = 0u; i < n; ++i) cases *= 7u;
        for (code = 0u; code < cases; ++code) {
            uint32_t x = code;
            for (i = 0u; i < n; ++i) { values[i] = (int32_t)(x % 7u) - 3; x /= 7u; }
            for (int32_t query = -5; query <= 5; ++query) {
                assert(pc_table_nearest_index_i32(values, n, query, &got));
                assert(got == oracle(values, n, query));
                ++tested;
            }
        }
    }
    for (i = 0u; i < 100000u; ++i) {
        int32_t table[128], query = from_bits(next_u32());
        size_t nrandom = next_u32() % 128u + 1u, j;
        for (j = 0u; j < nrandom; ++j) table[j] = from_bits(next_u32());
        assert(pc_table_nearest_index_i32(table, nrandom, query, &got));
        assert(got == oracle(table, nrandom, query));
        ++tested;
    }
    for (i = 0u; i < 50000u; ++i) {
        int32_t table[128], query = from_bits(next_u32());
        size_t len = next_u32() % 128u + 1u, j, unsorted_index, sorted_index;
        /* Include duplicate keys while retaining sorted order. */
        for (j = 0u; j < len; ++j) table[j] = (int32_t)(j / 2u) - (int32_t)(len / 4u);
        assert(pc_table_nearest_index_i32(table, len, query, &unsorted_index));
        assert(pc_nearest_sorted_i32(table, len, query, &sorted_index));
        assert(unsorted_index == sorted_index);
        ++tested;
    }
    {
        static const int32_t tie[] = {1, -1, 1};
        static const int32_t extremes[] = {INT32_MIN, INT32_MAX};
        assert(pc_table_nearest_index_i32(tie, 3u, 0, &got) && got == 0);
        assert(pc_table_nearest_index_i32(tie, 3u, 1, &got) && got == 0);
        assert(pc_table_nearest_index_i32(extremes, 2u, 0, &got) && got == 1u);
    }
    got = 99;
    assert(!pc_table_nearest_index_i32(NULL, 1u, 0, &got) && got == 99);
    assert(!pc_table_nearest_index_i32(values, 0u, 0, &got) && got == 99);
    assert(!pc_table_nearest_index_i32(values, 5u, 0, NULL));
    printf("nearest table tests passed: exhaustive+seeded=%lu\n", (unsigned long)tested);
    return 0;
}