#include "pc_block_minmax_u8.h"
#include <stdint.h>
#include <stdio.h>

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
static uint32_t state=UINT32_C(0x3491a55a);
static uint32_t next(void) { state^=state<<13; state^=state>>17; state^=state<<5; return state; }
int main(void)
{
    uint8_t a[16], lo=77u, hi=88u;
    unsigned x,y,i,j;
    CHECK(pc_block_minmax_u8((const uint8_t[]){9u},1u,&lo,&hi) && lo==9u && hi==9u);
    CHECK(pc_block_minmax_u8((const uint8_t[]){5u,0u,255u,5u},4u,&lo,&hi) && lo==0u && hi==255u);
    for(x=0;x<256u;++x) for(y=0;y<256u;++y) {
        uint8_t pair[2]={(uint8_t)x,(uint8_t)y};
        CHECK(pc_block_minmax_u8(pair,2u,&lo,&hi));
        CHECK(lo==(x<y?x:y) && hi==(x>y?x:y));
    }
    lo=77u; hi=88u;
    CHECK(!pc_block_minmax_u8(NULL,1u,&lo,&hi) && lo==77u && hi==88u);
    CHECK(!pc_block_minmax_u8(a,0u,&lo,&hi) && lo==77u && hi==88u);
    CHECK(!pc_block_minmax_u8(a,1u,NULL,&hi) && hi==88u);
    CHECK(!pc_block_minmax_u8(a,1u,&lo,NULL) && lo==77u);
    CHECK(!pc_block_minmax_u8(a,1u,&lo,&lo) && lo==77u);
    for(i=0;i<100000u;++i) {
        unsigned n=1u+next()%16u, mn=255u,mx=0u;
        for(j=0;j<n;++j) { a[j]=(uint8_t)next(); if(a[j]<mn)mn=a[j]; if(a[j]>mx)mx=a[j]; }
        CHECK(pc_block_minmax_u8(a,n,&lo,&hi) && lo==mn && hi==mx);
    }
    puts("pc_block_minmax_u8 experiment: PASS (65,536 pairs, 100,000 seeded blocks)");
    return 0;
}