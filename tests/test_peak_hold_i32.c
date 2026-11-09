#include "peak_hold_i32.h"
#include <assert.h>
#include <limits.h>

int main(void)
{
    pc_peak_hold_i32_state s = RM_PEAK_HOLD_I32_STATE_INIT;
    pc_peak_hold_i32_state bad = { UINT32_MAX, true }, old = bad;
    assert(!s.initialized && s.peak_magnitude == 0u);
    assert(pc_peak_hold_i32(0, &s) && s.initialized && s.peak_magnitude == 0u);
    assert(pc_peak_hold_i32(-123, &s) && s.peak_magnitude == 123u);
    assert(pc_peak_hold_i32(100, &s) && s.peak_magnitude == 123u);
    assert(pc_peak_hold_i32(INT32_MIN, &s) && s.peak_magnitude == UINT32_C(0x80000000));
    assert(pc_peak_hold_i32(INT32_MAX, &s) && s.peak_magnitude == UINT32_C(0x80000000));
    s = (pc_peak_hold_i32_state)RM_PEAK_HOLD_I32_STATE_INIT;
    assert(pc_peak_hold_i32(-1, &s) && s.peak_magnitude == 1u);
    s = (pc_peak_hold_i32_state)RM_PEAK_HOLD_I32_STATE_INIT;
    assert(pc_peak_hold_i32(0, &s) && s.peak_magnitude == 0u);
    assert(!pc_peak_hold_i32(1, NULL));
    assert(!pc_peak_hold_i32(1, &bad) && bad.peak_magnitude == old.peak_magnitude && bad.initialized == old.initialized);
    return 0;
}
