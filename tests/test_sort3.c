#include "sort3_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

static uint32_t state=UINT32_C(0x1822feed);
static uint32_t next_word(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t next_i32(void){uint32_t u=next_word();return u<=(uint32_t)INT32_MAX?(int32_t)u:INT32_MIN+(int32_t)(u-UINT32_C(0x80000000));}
static void oracle(int32_t v[3],int32_t out[3]){int32_t low=v[0],high=v[0];int i;int64_t middle;
    for(i=1;i<3;++i){if(v[i]<low)low=v[i];if(v[i]>high)high=v[i];}
    middle=(int64_t)v[0]+v[1]+v[2]-(int64_t)low-high;
    out[0]=low;out[1]=(int32_t)middle;out[2]=high;}
int main(void){int32_t v[3],expected[3],a,b,c;uint32_t n;
    assert(!pc_sort3_i32(NULL));
    v[0]=INT32_MAX;v[1]=0;v[2]=INT32_MIN;assert(pc_sort3_i32(v));assert(v[0]==INT32_MIN&&v[1]==0&&v[2]==INT32_MAX);
    for(a=-64;a<=64;++a)for(b=-64;b<=64;++b)for(c=-64;c<=64;++c){v[0]=a;v[1]=b;v[2]=c;oracle(v,expected);assert(pc_sort3_i32(v));assert(v[0]==expected[0]&&v[1]==expected[1]&&v[2]==expected[2]);}
    for(n=0;n<200000;++n){a=next_i32();b=next_i32();c=next_i32();v[0]=a;v[1]=b;v[2]=c;oracle(v,expected);assert(pc_sort3_i32(v));assert(v[0]==expected[0]&&v[1]==expected[1]&&v[2]==expected[2]);}
    return 0;}