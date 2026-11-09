#include "peak_decay_i32.h"
#include <assert.h>
#include <limits.h>

int main(void)
{
    pc_peak_decay_i32_state s = PC_PEAK_DECAY_I32_STATE_INIT;
    pc_peak_decay_i32_state bad = { UINT32_MAX, true }, old = bad;
    assert(pc_peak_decay_i32(-10, 3u, &s) && s.magnitude == 10u);
    assert(pc_peak_decay_i32(0, 3u, &s) && s.magnitude == 7u);
    assert(pc_peak_decay_i32(-4, 3u, &s) && s.magnitude == 4u);
    assert(pc_peak_decay_i32(2, 9u, &s) && s.magnitude == 2u);
    assert(pc_peak_decay_i32(INT32_MIN, 1u, &s) && s.magnitude == UINT32_C(0x80000000));
    assert(pc_peak_decay_i32(0, UINT32_MAX, &s) && s.magnitude == 0u);
    s = (pc_peak_decay_i32_state)PC_PEAK_DECAY_I32_STATE_INIT;
    assert(pc_peak_decay_i32(5, UINT32_MAX, &s) && s.magnitude == 5u);
    assert(!pc_peak_decay_i32(1, 0u, NULL));
    assert(!pc_peak_decay_i32(1, 1u, &bad) && bad.magnitude == old.magnitude && bad.initialized == old.initialized);
    return 0;
}