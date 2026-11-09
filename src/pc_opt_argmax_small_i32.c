#include "pc_opt_argmax_small_i32.h"

bool pc_opt_argmax_small_i32(const int32_t *values, uint8_t count,
                             uint8_t *index)
{
    uint8_t best = 0u;
    uint8_t i;

    if (values == 0 || index == 0 || count == 0u || count > 8u) {
        return false;
    }
    for (i = 1u; i < count; ++i) {
        if (values[i] > values[best]) {
            best = i;
        }
    }
    *index = best;
    return true;
}