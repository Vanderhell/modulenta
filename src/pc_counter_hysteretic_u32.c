#include "pc_counter_hysteretic_u32.h"
#include <stddef.h>
bool pc_counter_hysteretic_u32(bool sample, uint32_t lower, uint32_t upper,
                               pc_counter_hysteretic_state *state)
{
    uint32_t count;
    bool active;
    if (state == NULL || lower >= upper || state->count > upper ||
        (state->active && state->count <= lower) ||
        (!state->active && state->count >= upper)) return false;
    count = state->count;
    active = state->active;
    if (sample) {
        if (count < upper) ++count;
    } else if (count > 0u) {
        --count;
    }
    if (!active && count >= upper) active = true;
    else if (active && count <= lower) active = false;
    state->count = count;
    state->active = active;
    return true;
}
