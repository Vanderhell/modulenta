#include "sort8_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

static uint32_t state=UINT32_C(0x1826feed);
static uint32_t next_word(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t next_i32(void){uint32_t u=next_word();return u<=(uint32_t)INT32_MAX?(int32_t)u:INT32_MIN+(int32_t)(u-UINT32_C(0x80000000));}
static int compare_i32(const void *lhs,const void *rhs){int32_t a=*(const int32_t*)lhs,b=*(const int32_t*)rhs;return(a>b)-(a<b);}
static void check(int32_t *v){int32_t expected[8];unsigned i;for(i=0;i<8;++i)expected[i]=v[i];qsort(expected,8,sizeof expected[0],compare_i32);assert(pc_sort8_i32(v));for(i=0;i<8;++i)assert(v[i]==expected[i]);}
int main(void){int32_t v[8];uint32_t n;assert(!pc_sort8_i32(NULL));
    v[0]=INT32_MAX;v[1]=INT32_MIN;v[2]=0;v[3]=INT32_MAX;v[4]=INT32_MIN;v[5]=-1;v[6]=1;v[7]=0;check(v);
    for(int32_t a=-2;a<=2;++a)for(int32_t b=-2;b<=2;++b)for(int32_t c=-2;c<=2;++c)for(int32_t d=-2;d<=2;++d)
    for(int32_t e=-2;e<=2;++e)for(int32_t f=-2;f<=2;++f)for(int32_t g=-2;g<=2;++g)for(int32_t h=-2;h<=2;++h){v[0]=a;v[1]=b;v[2]=c;v[3]=d;v[4]=e;v[5]=f;v[6]=g;v[7]=h;check(v);}
    for(n=0;n<200000;++n){for(unsigned i=0;i<8;++i)v[i]=next_i32();check(v);}return 0;}