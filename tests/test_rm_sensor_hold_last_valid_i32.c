#include "pc_sensor_hold_last_valid_i32.h"

#include <assert.h>
#include <limits.h>
#include <stdint.h>

int main(void)
{
    pc_sensor_hold_last_valid_i32_state state = { 0, false };
    int32_t output = 123;
    uint32_t i;
    uint32_t rng = UINT32_C(0x2556C0DE);
    int32_t expected = 0;
    bool have_expected = false;

    assert(pc_sensor_hold_last_valid_i32(&state, false, 7, &output) ==
           RM_SENSOR_HOLD_NO_VALUE);
    assert(output == 123 && !state.has_value);
    assert(pc_sensor_hold_last_valid_i32(&state, true, INT32_MIN, &output) ==
           RM_SENSOR_HOLD_VALUE);
    assert(output == INT32_MIN && state.last_value == INT32_MIN);
    assert(pc_sensor_hold_last_valid_i32(&state, false, INT32_MAX, &output) ==
           RM_SENSOR_HOLD_VALUE);
    assert(output == INT32_MIN && state.last_value == INT32_MIN);
    assert(pc_sensor_hold_last_valid_i32(&state, true, INT32_MAX, &output) ==
           RM_SENSOR_HOLD_VALUE);
    assert(output == INT32_MAX && state.last_value == INT32_MAX);

    {
        const pc_sensor_hold_last_valid_i32_state before = state;
        output = 456;
        assert(pc_sensor_hold_last_valid_i32(0, true, 9, &output) ==
               RM_SENSOR_HOLD_ERROR);
        assert(output == 456 && state.last_value == before.last_value &&
               state.has_value == before.has_value);
        assert(pc_sensor_hold_last_valid_i32(&state, true, 9, 0) ==
               RM_SENSOR_HOLD_ERROR);
        assert(state.last_value == before.last_value && state.has_value == before.has_value);
    }

    state.last_value = 0;
    state.has_value = false;
    output = 789;
    for (i = 0; i < UINT32_C(1000000); ++i) {
        int32_t sample;
        bool valid;
        pc_sensor_hold_last_valid_i32_result result;
        rng = rng * UINT32_C(1664525) + UINT32_C(1013904223);
        valid = (rng & UINT32_C(7)) != 0u;
        sample = (int32_t)((rng >> 1u) ^ i);
        result = pc_sensor_hold_last_valid_i32(&state, valid, sample, &output);
        if (valid) {
            expected = sample;
            have_expected = true;
        }
        if (have_expected) {
            assert(result == RM_SENSOR_HOLD_VALUE);
            assert(output == expected && state.last_value == expected);
        } else {
            assert(result == RM_SENSOR_HOLD_NO_VALUE);
            assert(output == 789 && !state.has_value);
        }
    }
    return 0;
}
