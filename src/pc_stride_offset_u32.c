#include <primitivecore/utility/general/bounded/pc_stride_offset_u32.h>
#include <stddef.h>
bool rm_stride_offset_u32(uint32_t index, uint32_t stride, uint32_t *offset)
{
    if (offset == NULL || (stride != 0u && index > UINT32_MAX / stride))
        return false;
    *offset = index * stride;
    return true;
}
