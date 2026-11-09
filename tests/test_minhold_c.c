#include "../include/pc_rssi_minhold_i32.h"

#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

static uint32_t rng = UINT32_C(0x3224cafe);

static uint32_t next_u32(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return rng;
}

static int32_t next_i32(void)
{
    uint32_t u = next_u32();
    if (u <= (uint32_t)INT32_MAX) return (int32_t)u;
    return INT32_MIN + (int32_t)(u - UINT32_C(0x80000000));
}

static int compare_i32(const void *lhs, const void *rhs)
{
    int32_t a = *(const int32_t *)lhs;
    int32_t b = *(const int32_t *)rhs;
    return (a > b) - (a < b);
}

int main(void)
{
    int32_t minimum = -80;
    assert(pc_rssi_minhold_i32(-70, &minimum) && minimum == -80);
    assert(pc_rssi_minhold_i32(-90, &minimum) && minimum == -90);
    assert(pc_rssi_minhold_i32(-90, &minimum) && minimum == -90);
    assert(pc_rssi_minhold_i32(INT32_MIN, &minimum) && minimum == INT32_MIN);
    assert(pc_rssi_minhold_i32(INT32_MAX, &minimum) && minimum == INT32_MIN);
    assert(!pc_rssi_minhold_i32(0, NULL));
    {
        int a, b;
        for (a = -128; a <= 127; ++a) {
            for (b = -128; b <= 127; ++b) {
                int32_t actual = (int32_t)a;
                int32_t pair[2] = {(int32_t)a, (int32_t)b};
                qsort(pair, 2, sizeof pair[0], compare_i32);
                assert(pc_rssi_minhold_i32((int32_t)b, &actual));
                assert(actual == pair[0]);
            }
        }
    }
    {
        int32_t actual = next_i32();
        int32_t expected = actual;
        unsigned i;
        for (i = 0; i < 100000u; ++i) {
            int32_t sample = next_i32();
            int32_t pair[2] = {expected, sample};
            qsort(pair, 2, sizeof pair[0], compare_i32);
            expected = pair[0];
            assert(pc_rssi_minhold_i32(sample, &actual));
            assert(actual == expected);
        }
    }
    return 0;
}