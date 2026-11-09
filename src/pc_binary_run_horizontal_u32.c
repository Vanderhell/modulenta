#include "pc_binary_run_horizontal_u32.h"
#include <stddef.h>

bool pc_binary_run_horizontal_u32(const uint8_t *row, uint32_t width,
                                  uint32_t start_x, uint32_t *run_length)
{
    uint32_t end;
    if (row == NULL || run_length == NULL || width == 0u || start_x > width) return false;
    end = start_x;
    while (end < width && row[end] != 0u) ++end;
    *run_length = end - start_x;
    return true;
}