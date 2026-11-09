#include "../include/pc_tcpseq_sack_span_u32.h"

#include <stddef.h>
#include <stdint.h>

static uint32_t state = UINT32_C(0x4109C0DE);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static int oracle(uint32_t left, uint32_t right, uint32_t *span)
{
    int64_t d = (int64_t)right - (int64_t)left;
    if (d < 0) d += INT64_C(4294967296);
    if (span == NULL || d == 0 || d >= INT64_C(2147483648)) return 0;
    *span = (uint32_t)d;
    return 1;
}

int main(void)
{
    uint32_t left, right, actual, expected, i, offset;
    for (offset = 0u; offset < 256u; ++offset) {
        left = UINT32_MAX - 255u + offset;
        for (right = 0u; right < 256u; ++right) {
            actual = expected = UINT32_C(0xA5A5A5A5);
            if (pc_tcpseq_sack_span_u32(left, right, &actual) != oracle(left, right, &expected)) return 1;
            if (actual != expected) return 2;
        }
    }
    if (pc_tcpseq_sack_span_u32(UINT32_MAX - 1u, 1u, &actual) == 0 || actual != 3u) return 3;
    actual = 77u;
    if (pc_tcpseq_sack_span_u32(10u, 10u, &actual) || actual != 77u) return 4;
    if (pc_tcpseq_sack_span_u32(0u, UINT32_C(0x80000000), &actual) || actual != 77u) return 5;
    if (pc_tcpseq_sack_span_u32(0u, UINT32_C(0x80000001), &actual) || actual != 77u) return 6;
    if (pc_tcpseq_sack_span_u32(10u, 9u, &actual) || actual != 77u) return 7;
    if (pc_tcpseq_sack_span_u32(0u, 1u, NULL)) return 8;
    for (i = 0u; i < UINT32_C(1000000); ++i) {
        left = next_u32(); right = next_u32();
        actual = expected = UINT32_C(0x5AA55AA5);
        if (pc_tcpseq_sack_span_u32(left, right, &actual) != oracle(left, right, &expected)) return 9;
        if (actual != expected) return 10;
    }
    return 0;
}
