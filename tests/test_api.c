#include "pc_knn_second_index_u32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t state = UINT32_C(0x4535A11C);
static uint32_t next_u32(void)
{
    state ^= state << 13u; state ^= state >> 17u; state ^= state << 5u;
    return state;
}
static uint32_t reference(const uint32_t *d, uint32_t n)
{
    uint32_t first = 0u, second = 1u, i;
    if (d[second] < d[first]) { uint32_t t=first; first=second; second=t; }
    for (i=2u; i<n; ++i) {
        if (d[i] < d[first]) { second=first; first=i; }
        else if (d[i] < d[second]) second=i;
    }
    return second;
}
int main(void)
{
    uint32_t d[8], out, n, code, cases=0u, i, j;
    out=UINT32_C(0xA5A5A5A5);
    assert(!pc_knn_second_index_u32(0,2u,&out) && out==UINT32_C(0xA5A5A5A5));
    assert(!pc_knn_second_index_u32(d,2u,0));
    assert(!pc_knn_second_index_u32(d,0u,&out) && out==UINT32_C(0xA5A5A5A5));
    assert(!pc_knn_second_index_u32(d,1u,&out) && out==UINT32_C(0xA5A5A5A5));
    { const uint32_t ties[]={5u,5u,5u}; assert(pc_knn_second_index_u32(ties,3u,&out)&&out==1u); }
    { const uint32_t full[]={UINT32_MAX,0u,UINT32_C(0x80000000),0u}; assert(pc_knn_second_index_u32(full,4u,&out)&&out==3u); }
    for(n=2u;n<=7u;++n){
        uint32_t total=1u;
        for(i=0u;i<n;++i) total*=4u;
        for(code=0u;code<total;++code){
            uint32_t x=code;
            for(i=0u;i<n;++i){d[i]=x&3u;x>>=2u;}
            assert(pc_knn_second_index_u32(d,n,&out));
            assert(out==reference(d,n)); ++cases;
        }
    }
    for(i=0u;i<100000u;++i){
        for(j=0u;j<8u;++j)d[j]=next_u32();
        n=(i%7u)+2u;
        assert(pc_knn_second_index_u32(d,n,&out));
        assert(out==reference(d,n));++cases;
    }
    printf("knn second index C differential PASS: %u cases\n",(unsigned)cases);
    return 0;
}


