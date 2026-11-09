#include "pc_peak_to_peak_running_i32.h"

#include <limits.h>
#include <stdint.h>

int main(void)
{
    pc_peak_to_peak_running_i32_state state;
    uint32_t span = 0u;
    pc_peak_to_peak_running_i32_reset(&state);
    if (!pc_peak_to_peak_running_i32_update(&state, INT32_MIN, &span) || span != 0u)
        return 1;
    if (!pc_peak_to_peak_running_i32_update(&state, INT32_MAX, &span) ||
        span != UINT32_MAX) return 2;
    pc_peak_to_peak_running_i32_reset(&state);
    return state.initialized ? 3 : 0;
}
