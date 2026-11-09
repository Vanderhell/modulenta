/* Held-out cross-family validation source; dependency is outside this product. */
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int32_t values[5];
    bool ok;
    uint32_t state=UINT32_C(0x65f42a91);
    size_t n,limit,code,total=0u;
    unsigned j,i;
    assert(pc_constraint_sum_i32(NULL,0u,0,&ok)&&ok);
    assert(pc_constraint_sum_i32(NULL,0u,-1,&ok)&&!ok);
    assert(!pc_constraint_sum_i32(NULL,1u,0,&ok));
    assert(!pc_constraint_sum_i32(values,0u,0,NULL));
    values[0]=INT32_MAX;values[1]=INT32_MIN;
    assert(pc_constraint_sum_i32(values,2u,-1,&ok)&&ok);
    assert(pc_constraint_sum_i32(values,2u,-2,&ok)&&!ok);
    values[0]=INT32_MAX;values[1]=INT32_MAX;values[2]=INT32_MIN;
    assert(pc_constraint_sum_i32(values,3u,INT32_MAX-2LL,&ok)&&!ok);
    assert(pc_constraint_sum_i32(values,3u,INT32_MAX-1LL,&ok)&&ok);
    ok=true;
    assert(!pc_constraint_sum_i32(NULL,1u,0,&ok)&&ok);
#if SIZE_MAX > UINT32_MAX
    assert(!pc_constraint_sum_i32(values,(size_t)UINT32_MAX+1u,0,&ok)&&ok);
#endif
    for(n=0u;n<=5u;++n){
        size_t number=1u;
        for(j=0;j<n;++j)number*=5u;
        for(code=0;code<number;++code){
            size_t t=code;
            int64_t sum=0;
            for(j=0;j<n;++j){values[j]=(int32_t)(t%5u)-2;t/=5u;sum+=values[j];}
            for(limit=0u;limit<=10u;++limit){
                const int64_t bound=(int64_t)limit-5;
                assert(pc_constraint_sum_i32(values,n,bound,&ok));
                assert(ok==(sum<=bound));
                ++total;
            }
        }
    }
    for(i=0;i<200000u;++i){
        int64_t sum=0,bound;
        n=(size_t)(state%6u);state^=state<<13;state^=state>>17;state^=state<<5;
        for(j=0;j<n;++j){state^=state<<13;state^=state>>17;state^=state<<5;values[j]=(int32_t)state;sum+=values[j];}
        state^=state<<13;state^=state>>17;state^=state<<5;bound=(int32_t)state;
        assert(pc_constraint_sum_i32(values,n,bound,&ok));
        assert(ok==(sum<=bound));
    }
    printf("sum constraint tests passed (%zu exhaustive cases, 200000 seeded)\n",total);
    return 0;
}