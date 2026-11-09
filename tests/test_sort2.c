#include "sort2_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

static uint32_t state=UINT32_C(0x1821cafe);
static uint32_t next_word(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t next_i32(void){uint32_t u=next_word();return u<=(uint32_t)INT32_MAX?(int32_t)u:INT32_MIN+(int32_t)(u-UINT32_C(0x80000000));}
int main(void){int32_t v[2],a,b;uint32_t n;
    assert(!pc_sort2_i32(NULL));
    v[0]=INT32_MAX;v[1]=INT32_MIN;assert(pc_sort2_i32(v));assert(v[0]==INT32_MIN&&v[1]==INT32_MAX);
    v[0]=4;v[1]=4;assert(pc_sort2_i32(v));assert(v[0]==4&&v[1]==4);
    for(a=-128;a<=128;++a)for(b=-128;b<=128;++b){v[0]=a;v[1]=b;assert(pc_sort2_i32(v));assert(v[0]<=v[1]);assert(v[0]==(a<b?a:b));assert(v[1]==(a<b?b:a));}
    for(n=0;n<200000;++n){a=next_i32();b=next_i32();v[0]=a;v[1]=b;assert(pc_sort2_i32(v));assert(v[0]==(a<b?a:b));assert(v[1]==(a<b?b:a));}
    return 0;
}
