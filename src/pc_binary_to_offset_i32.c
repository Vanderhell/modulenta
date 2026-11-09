#include "pc_binary_to_offset_i32.h"
#include <stddef.h>

bool rm_binary_to_offset_i32(int32_t binary, uint32_t offset, uint32_t *code)
{
    if (code == NULL) {
        return false;
    }
    uint32_t shifted;
    if (binary < 0) {
        const uint32_t magnitude = 0u - (uint32_t)binary;
        if (offset < magnitude) {
            return false;
        }
        shifted = offset - magnitude;
    } else {
        const uint32_t positive = (uint32_t)binary;
        if (offset > UINT32_MAX - positive) {
            return false;
        }
        shifted = offset + positive;
    }
    *code = shifted;
    return true;
}