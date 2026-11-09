#include "pc_approx_uniform_knots_u32.h"

#include <stddef.h>

bool pc_approx_uniform_knots_u32(uint32_t sample_count, uint32_t knot_count,
                                 uint32_t *indices)
{
    uint32_t intervals, quotient, remainder;
    uint32_t index = 0u;
    uint32_t error = 0u;
    uint32_t i;

    if (indices == NULL || sample_count < 2u || knot_count < 2u ||
        knot_count > sample_count) return false;

    intervals = knot_count - 1u;
    quotient = (sample_count - 1u) / intervals;
    remainder = (sample_count - 1u) % intervals;
    indices[0] = 0u;
    for (i = 1u; i < knot_count; ++i) {
        index += quotient;
        if (remainder != 0u) {
            uint32_t threshold = intervals - remainder;
            if (error >= threshold) {
                ++index;
                error -= threshold;
            } else {
                error += remainder;
            }
        }
        indices[i] = index;
    }
    return true;
}