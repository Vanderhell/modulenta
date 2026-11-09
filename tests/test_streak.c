#include "pc_packet_success_streak_u32.h"

#include <assert.h>
#include <stdint.h>

static uint32_t next_random(uint32_t *state)
{
    uint32_t x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;
    return x;
}

int main(void)
{
    uint32_t value, state = UINT32_C(0x3252C0DE);
    uint32_t i;
    bool success;
    assert(pc_packet_success_streak_u32(false, 0u) == 0u);
    assert(pc_packet_success_streak_u32(false, UINT32_MAX) == 0u);
    assert(pc_packet_success_streak_u32(true, 0u) == 1u);
    assert(pc_packet_success_streak_u32(true, UINT32_MAX - 1u) == UINT32_MAX);
    assert(pc_packet_success_streak_u32(true, UINT32_MAX) == UINT32_MAX);
    for (value = 0u; value <= 65535u; ++value) {
        assert(pc_packet_success_streak_u32(false, value) == 0u);
        assert(pc_packet_success_streak_u32(true, value) == value + 1u);
    }
    for (i = 0u; i < 1000000u; ++i) {
        value = next_random(&state);
        success = (next_random(&state) & 1u) != 0u;
        if (success) {
            uint32_t expected = value == UINT32_MAX ? UINT32_MAX : value + 1u;
            assert(pc_packet_success_streak_u32(success, value) == expected);
        } else {
            assert(pc_packet_success_streak_u32(success, value) == 0u);
        }
    }
    value = 0u;
    for (i = 0u; i < 1000000u; ++i) value = pc_packet_success_streak_u32(true, value);
    assert(value == 1000000u);
    value = pc_packet_success_streak_u32(false, value);
    assert(value == 0u);
    return 0;
}