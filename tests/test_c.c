#include "pc_pool_block_index_u32.h"
#include <stdint.h>
#include <stdio.h>
int main(void)
{
    uint32_t out=77u, x=UINT32_C(0x4801);
    if (!pc_pool_block_index_u32(48u,16u,4u,&out) || out!=3u) return 1;
    out=77u;
    if (pc_pool_block_index_u32(17u,16u,4u,&out) || out!=77u) return 2;
    if (pc_pool_block_index_u32(64u,16u,4u,&out) || out!=77u) return 3;
    for (uint32_t i=0;i<100000u;++i) {
        uint32_t off,size,count,expected;
        x=x*UINT32_C(1664525)+UINT32_C(1013904223); off=x;
        x=x*UINT32_C(1664525)+UINT32_C(1013904223); size=x;
        x=x*UINT32_C(1664525)+UINT32_C(1013904223); count=x;
        expected=size!=0u && count!=0u && off%size==0u && off/size<count;
        out=77u;
        if (pc_pool_block_index_u32(off,size,count,&out)!=(expected!=0u)) return 4;
        if (expected && out!=off/size) return 5;
        if (!expected && out!=77u) return 6;
    }
    (void)puts("pool block index C regression PASS");
    return 0;
}
