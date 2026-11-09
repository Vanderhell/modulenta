#include "pc_opt_argmax_small_i32.h"
#include <assert.h>
#include <limits.h>
#include <stddef.h>

static int32_t values[8];
static unsigned total;
static void check(size_t n)
{
    uint8_t index=99u;
    int32_t maximum=values[0]; size_t expected=0u;
    for(size_t i=1;i<n;++i) if(values[i]>maximum){maximum=values[i];expected=i;}
    assert(pc_opt_argmax_small_i32(values,(uint8_t)n,&index));
    assert(index==expected && values[index]==maximum);
    ++total;
}
static void enumerate(size_t pos,size_t n)
{
    if(pos==n){check(n);return;}
    for(int32_t v=-2;v<=2;++v){values[pos]=v;enumerate(pos+1u,n);}
}
int main(void)
{
    uint8_t index=77u;
    for(size_t n=1;n<=6;++n)enumerate(0u,n);
    assert(total==19530u);
    {const int32_t a[8]={4,3,2,1,-1,0,1,2};
     assert(pc_opt_argmax_small_i32(a,8u,&index)&&index==0u);}
    {const int32_t a[8]={INT32_MIN,0,INT32_MAX,INT32_MAX,INT32_MIN,0,-1,1};
     assert(pc_opt_argmax_small_i32(a,8u,&index)&&index==2u);}
    {const int32_t a[3]={-4,-4,-4};
     assert(pc_opt_argmax_small_i32(a,3u,&index)&&index==0u);}
    index=77u;
    assert(!pc_opt_argmax_small_i32(NULL,1u,&index)&&index==77u);
    assert(!pc_opt_argmax_small_i32(values,0u,&index)&&index==77u);
    assert(!pc_opt_argmax_small_i32(values,9u,&index)&&index==77u);
    assert(!pc_opt_argmax_small_i32(values,1u,NULL));
    return 0;
}