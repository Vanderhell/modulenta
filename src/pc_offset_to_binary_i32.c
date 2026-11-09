#include "pc_offset_to_binary_i32.h"
#include <stddef.h>

bool pc_offset_to_binary_i32(uint32_t code, uint32_t offset, int32_t *binary)
{
    if (binary == NULL) {
        return false;
    }
    if (code >= offset) {
        const uint32_t positive = code - offset;
        if (positive > (uint32_t)INT32_MAX) {
            return false;
        }
        *binary = (int32_t)positive;
    } else {
        const uint32_t magnitude = offset - code;
        if (magnitude > (UINT32_C(1) << 31)) {
            return false;
        }
        if (magnitude == (UINT32_C(1) << 31)) {
            *binary = INT32_MIN;
        } else {
            *binary = -(int32_t)magnitude;
        }
    }
    return true;
}