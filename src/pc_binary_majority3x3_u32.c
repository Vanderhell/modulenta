#include "pc_binary_majority3x3_u32.h"
#include <stddef.h>

bool pc_binary_majority3x3_u32(uint32_t neighborhood, uint32_t *result)
{
    uint32_t bits, count=0u;
    if (result == NULL || (neighborhood & ~UINT32_C(0x1FF)) != 0u) return false;
    bits=neighborhood;
    while(bits!=0u){count+=bits&1u;bits>>=1u;}
    *result=(count>=5u)?1u:0u;
    return true;
}