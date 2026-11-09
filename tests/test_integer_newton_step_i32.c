#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool pc_integer_newton_step_i32(int32_t x, int32_t fx, int32_t dfx, int32_t *out_x);

static int64_t trunc_div(int64_t n, int64_t d)
{
    const int64_t q = (n < 0 ? -n : n) / (d < 0 ? -d : d);
    return ((n < 0) != (d < 0)) ? -q : q;
}

static bool reference(int32_t x, int32_t fx, int32_t dfx, int32_t *out)
{
    int64_t r;
    if (dfx == 0) return false;
    r = (int64_t)x - trunc_div(fx, dfx);
    if (r < INT32_MIN || r > INT32_MAX) return false;
    *out = (int32_t)r;
    return true;
}

int main(void)
{
    int32_t out, expected;
    int x, f, d;
    uint32_t state = UINT32_C(0xc0ffee51);
    unsigned i;
    assert(pc_integer_newton_step_i32(10, 3, 2, &out) && out == 9);
    assert(pc_integer_newton_step_i32(10, -3, 2, &out) && out == 11);
    assert(pc_integer_newton_step_i32(10, 3, -2, &out) && out == 11);
    assert(!pc_integer_newton_step_i32(10, 1, 0, &out));
    assert(pc_integer_newton_step_i32(0, INT32_MIN, -1, &out) && out == INT32_MIN);
    out = 42;
    assert(!pc_integer_newton_step_i32(INT32_MIN, 1, 1, &out) && out == 42);
    assert(!pc_integer_newton_step_i32(0, 1, 1, NULL));
    for (x=-8;x<=8;++x) for (f=-8;f<=8;++f) for (d=-8;d<=8;++d) {
        bool want = reference(x,f,d,&expected);
        bool got = pc_integer_newton_step_i32(x,f,d,&out);
        assert(got == want);
        if (want) assert(out == expected);
    }
    for (i=0;i<200000u;++i) {
        int32_t sx, sf, sd;
        state ^= state << 13; state ^= state >> 17; state ^= state << 5; sx=(int32_t)state;
        state ^= state << 13; state ^= state >> 17; state ^= state << 5; sf=(int32_t)state;
        state ^= state << 13; state ^= state >> 17; state ^= state << 5; sd=(int32_t)state;
        if (sd == 0) sd = 1;
        {
            bool want = reference(sx,sf,sd,&expected);
            bool got = pc_integer_newton_step_i32(sx,sf,sd,&out);
            assert(got == want);
            if (want) assert(out == expected);
        }
    }
    puts("integer Newton arithmetic tests passed (4913 exhaustive, 200000 seeded)");
    return 0;
}
