#include "pc_accumulate_square_i32.h"
#include <stddef.h>

bool pc_accumulate_square_i32(int32_t value, uint64_t *accumulator)
{
    int64_t widened;
    uint64_t magnitude, square;
    if (accumulator == NULL) return false;
    widened = value;
    magnitude = (uint64_t)((widened < 0) ? -widened : widened);
    square = magnitude * magnitude;
    if (UINT64_MAX - *accumulator < square) return false;
    *accumulator += square;
    return true;
}
