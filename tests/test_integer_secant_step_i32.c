#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool pc_integer_secant_step_i32(int32_t x0, int32_t x1, int32_t f0, int32_t f1, int32_t *out_x);

static bool reference(int32_t x0, int32_t x1, int32_t f0, int32_t f1, int32_t *out)
{
    const int64_t dx=(int64_t)x1-x0, df=(int64_t)f1-f0;
    int64_t q, lo, hi;
    if (df==0) return false;
    q=((int64_t)f1*dx)/df;
    lo=(int64_t)x1-INT32_MAX; hi=(int64_t)x1-INT32_MIN;
    if(q<lo || q>hi) return false;
    *out=(int32_t)((int64_t)x1-q); return true;
}

int main(void)
{
    int32_t out, expected;
    int a,b,c,d;
    uint32_t state=UINT32_C(0x51ec4a73);
    unsigned i;
    assert(pc_integer_secant_step_i32(0,1,0,1,&out) && out==0);
    assert(!pc_integer_secant_step_i32(0,0,1,1,&out));
    assert(!pc_integer_secant_step_i32(0,1,0,1,NULL));
    assert(pc_integer_secant_step_i32(INT32_MIN,INT32_MAX,0,1,&out));
    out=17;
    assert(!pc_integer_secant_step_i32(0,INT32_MAX,INT32_MAX-1,INT32_MAX,&out) && out==17);
    for(a=-3;a<=3;++a)for(b=-3;b<=3;++b)for(c=-3;c<=3;++c)for(d=-3;d<=3;++d){
        bool want=reference(a,b,c,d,&expected), got=pc_integer_secant_step_i32(a,b,c,d,&out);
        assert(got==want); if(want)assert(out==expected);
    }
    for(i=0;i<200000u;++i){
        int32_t v[4]; unsigned j;
        for(j=0;j<4;++j){state^=state<<13;state^=state>>17;state^=state<<5;v[j]=(int32_t)state;}
        {bool want=reference(v[0],v[1],v[2],v[3],&expected),got=pc_integer_secant_step_i32(v[0],v[1],v[2],v[3],&out);
         assert(got==want);if(want)assert(out==expected);}
    }
    puts("integer secant tests passed (2401 exhaustive, 200000 seeded)");
    return 0;
}