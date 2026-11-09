#include "../include/pc_lookup_mirrored_i32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng = 0x852C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}

static size_t oracle_index(size_t count, int32_t index)
{
    int64_t period = (int64_t)count * 2;
    int64_t r = (int64_t)index % period;
    if (r < 0) r += period;
    return (size_t)(r < (int64_t)count ? r : period - 1 - r);
}

int main(void)
{
    static const int32_t convention_table[] = {10, 20, 30};
    static const int32_t edge_inclusive_expected[] = {
        10, 20, 30, 30, 20, 10, 10, 20, 30, 30, 20, 10, 10
    };
    int32_t table[257], got;
    size_t n, i;
    int64_t probe;
    for (n = 1u; n <= 257u; ++n) {
        for (i = 0u; i < n; ++i) table[i] = (int32_t)next_u32();
        for (probe = -((int64_t)n * 3 + 3); probe <= (int64_t)n * 3 + 3; ++probe) {
            assert(pc_lookup_mirrored_i32(table, n, (int32_t)probe, &got));
            assert(got == table[oracle_index(n, (int32_t)probe)]);
        }
        for (i = 0u; i < 2500u; ++i) {
            int32_t index = (int32_t)next_u32();
            assert(pc_lookup_mirrored_i32(table, n, index, &got));
            assert(got == table[oracle_index(n, index)]);
        }
    }
    for (n = 1u; n <= 257u; ++n) {
        assert(pc_lookup_mirrored_i32(table, n, INT32_MIN, &got));
        assert(got == table[oracle_index(n, INT32_MIN)]);
        assert(pc_lookup_mirrored_i32(table, n, INT32_MAX, &got));
        assert(got == table[oracle_index(n, INT32_MAX)]);
    }
    for (i = 0u; i < 13u; ++i) {
        int32_t index = (int32_t)i - 6;
        assert(pc_lookup_mirrored_i32(convention_table, 3u, index, &got));
        assert(got == edge_inclusive_expected[i]);
    }
    got = 123;
    assert(!pc_lookup_mirrored_i32(NULL, 1u, 0, &got) && got == 123);
    assert(!pc_lookup_mirrored_i32(table, 0u, 0, &got) && got == 123);
    assert(!pc_lookup_mirrored_i32(table, 257u, 0, NULL));
    puts("lookup mirrored tests passed: 257 sizes, 642.5k seeded cases and boundary sweeps");
    return 0;
}