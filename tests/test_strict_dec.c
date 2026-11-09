#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "../include/strict_dec_i32.h"
#include "../../../../include/roundmath/pc_is_strict_dec_i32.h"

static int reference(const int32_t *a, size_t n)
{
    if (a == NULL) return n == 0u;
    for (size_t i = 1u; i < n; ++i) if (a[i - 1u] <= a[i]) return 0;
    return 1;
}

static int matches(const int32_t *a, size_t n)
{
    const int expected = reference(a, n);
    return (int)pc_is_strict_dec_i32_experiment(a, n) == expected &&
           (int)pc_is_strict_dec_i32(a, n) == expected;
}

static uint32_t state = UINT32_C(0x1104f00d);
static uint32_t next_u32(void)
{
    state ^= state << 13; state ^= state >> 17; state ^= state << 5; return state;
}

int main(void)
{
    int32_t a[64]; unsigned long long cases = 0u;
    for (size_t n = 0u; n <= 5u; ++n) {
        uint32_t total = 1u; for (size_t i = 0u; i < n; ++i) total *= 5u;
        for (uint32_t code = 0u; code < total; ++code) {
            uint32_t v = code;
            for (size_t i = 0u; i < n; ++i) { a[i] = (int32_t)(v % 5u) - 2; v /= 5u; }
            if (!matches(n ? a : NULL, n)) return 1;
            ++cases;
        }
    }
    {
        const int32_t e[] = {INT32_MIN, INT32_MIN + 1, -1, 0, 1, INT32_MAX - 1, INT32_MAX};
        for (size_t i = 0u; i < 7u; ++i) for (size_t j = 0u; j < 7u; ++j) {
            a[0] = e[i]; a[1] = e[j]; if (!matches(a, 2u)) return 2; ++cases;
        }
    }
    if (!matches(NULL, 0u) || !matches(NULL, 1u)) return 3;
    for (unsigned k = 0u; k < 100000u; ++k) {
        const size_t n = (size_t)(next_u32() % 65u);
        for (size_t i = 0u; i < n; ++i) a[i] = (int32_t)next_u32();
        if (!matches(n ? a : NULL, n)) return 4;
        ++cases;
    }
    printf("PASS strict decreasing relation over %llu arrays\n", cases); return 0;
}
