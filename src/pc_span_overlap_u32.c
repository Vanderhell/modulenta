#include "primitivecore/geometry/intervals/pc_span_overlap_u32.h"

bool pc_span_overlap_u32(uint32_t a_start, uint32_t a_length,
                         uint32_t b_start, uint32_t b_length)
{
    if (a_length > UINT32_MAX - a_start ||
        b_length > UINT32_MAX - b_start ||
        a_length == 0u || b_length == 0u) {
        return false;
    }
    if (a_start <= b_start) {
        return b_start - a_start < a_length;
    }
    return a_start - b_start < b_length;
}
