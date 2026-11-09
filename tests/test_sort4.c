#include "sort4_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

static uint32_t state=UINT32_C(0x1823feed);
static uint32_t next_word(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t next_i32(void){uint32_t u=next_word();return u<=(uint32_t)INT32_MAX?(int32_t)u:INT32_MIN+(int32_t)(u-UINT32_C(0x80000000));}
static void oracle(const int32_t *v,int32_t *out){unsigned i,j;int32_t key;for(i=0;i<4;++i)out[i]=v[i];
    for(i=1;i<4;++i){key=out[i];j=i;while(j>0&&out[j-1]>key){out[j]=out[j-1];--j;}out[j]=key;}}
int main(void){int32_t v[4],expected[4],a,b,c,d;uint32_t n;
    assert(!pc_sort4_i32(NULL));
    v[0]=INT32_MAX;v[1]=INT32_MIN;v[2]=0;v[3]=INT32_MIN;assert(pc_sort4_i32(v));assert(v[0]==INT32_MIN&&v[1]==INT32_MIN&&v[2]==0&&v[3]==INT32_MAX);
    for(a=-10;a<=10;++a)for(b=-10;b<=10;++b)for(c=-10;c<=10;++c)for(d=-10;d<=10;++d){int32_t in[4]={a,b,c,d};oracle(in,expected);for(unsigned i=0;i<4;++i)v[i]=in[i];assert(pc_sort4_i32(v));for(unsigned i=0;i<4;++i)assert(v[i]==expected[i]);}
    for(n=0;n<200000;++n){a=next_i32();b=next_i32();c=next_i32();d=next_i32();int32_t in[4]={a,b,c,d};oracle(in,expected);for(unsigned i=0;i<4;++i)v[i]=in[i];assert(pc_sort4_i32(v));for(unsigned i=0;i<4;++i)assert(v[i]==expected[i]);}
    return 0;}