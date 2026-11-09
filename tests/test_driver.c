#include "peak_decay_i32.h"
#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    uint32_t initialized, held, decay, count, i;
    int32_t sample;
    pc_peak_decay_i32_state state;
    while (scanf("%u %" SCNu32 " %u %u", &initialized, &held, &decay, &count) == 4) {
        if (initialized > 1u) return 2;
        state.initialized = initialized != 0u;
        state.magnitude = held;
        for (i = 0u; i < count; ++i) {
            if (scanf("%" SCNd32, &sample) != 1) return 3;
            if (!pc_peak_decay_i32(sample, decay, &state)) break;
        }
        if (i != count) printf("invalid:%u:%" PRIu32 "\n", state.initialized ? 1u : 0u, state.magnitude);
        else printf("ok:%u:%" PRIu32 "\n", state.initialized ? 1u : 0u, state.magnitude);
    }
    return 0;
}
