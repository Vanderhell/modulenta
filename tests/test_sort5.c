#include "sort5_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

static uint32_t state=UINT32_C(0x1824feed);
static uint32_t next_word(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t next_i32(void){uint32_t u=next_word();return u<=(uint32_t)INT32_MAX?(int32_t)u:INT32_MIN+(int32_t)(u-UINT32_C(0x80000000));}
static void oracle(const int32_t *v,int32_t *out){unsigned i,j;int32_t key;for(i=0;i<5;++i)out[i]=v[i];
    for(i=1;i<5;++i){key=out[i];j=i;while(j>0&&out[j-1]>key){out[j]=out[j-1];--j;}out[j]=key;}}
int main(void){int32_t v[5],expected[5];uint32_t n;unsigned i;
    assert(!pc_sort5_i32(NULL));
    v[0]=INT32_MAX;v[1]=INT32_MIN;v[2]=0;v[3]=INT32_MIN;v[4]=INT32_MAX;
    assert(pc_sort5_i32(v));assert(v[0]==INT32_MIN&&v[1]==INT32_MIN&&v[2]==0&&v[3]==INT32_MAX&&v[4]==INT32_MAX);
    for(int32_t a=-6;a<=6;++a)for(int32_t b=-6;b<=6;++b)for(int32_t c=-6;c<=6;++c)for(int32_t d=-6;d<=6;++d)for(int32_t e=-6;e<=6;++e){int32_t in[5]={a,b,c,d,e};oracle(in,expected);for(i=0;i<5;++i)v[i]=in[i];assert(pc_sort5_i32(v));for(i=0;i<5;++i)assert(v[i]==expected[i]);}
    for(n=0;n<200000;++n){int32_t in[5];for(i=0;i<5;++i){in[i]=next_i32();v[i]=in[i];}oracle(in,expected);assert(pc_sort5_i32(v));for(i=0;i<5;++i)assert(v[i]==expected[i]);}
    return 0;}