#include "pc_huber_clip_i32.h"
#include <limits.h>
#include <stdint.h>
#define CHECK(e) do { if (!(e)) return __LINE__; } while (0)
static uint32_t next(uint32_t *s){*s^=*s<<13;*s^=*s>>17;*s^=*s<<5;return *s;}
int main(void){
 static const int32_t xs[]={INT32_MIN,INT32_MIN+1,-100,-2,-1,0,1,2,100,INT32_MAX-1,INT32_MAX};
 static const uint32_t ts[]={0,1,2,99,100,INT32_MAX,UINT32_C(2147483648),UINT32_MAX};
 uint32_t i,j,s=UINT32_C(0x241a5eed); int32_t out, expected, x; uint32_t t;
 CHECK(!pc_huber_clip_i32(1,1,0));
 for(i=0;i<sizeof(xs)/sizeof(xs[0]);i++)for(j=0;j<sizeof(ts)/sizeof(ts[0]);j++){
  x=xs[i];t=ts[j];CHECK(pc_huber_clip_i32(x,t,&out));
  expected=t>=UINT32_C(2147483648)?x:(x>(int64_t)t?(int32_t)t:(x<-(int64_t)t?-(int32_t)t:x));
  CHECK(out==expected);CHECK((out>=-(int64_t)t&&out<=(int64_t)t)||t>=UINT32_C(2147483648));
 }
 for(i=0;i<1000000;i++){
  uint32_t ux=next(&s),ut=next(&s); x=(int32_t)ux;t=ut;
  CHECK(pc_huber_clip_i32(x,t,&out));
  expected=t>=UINT32_C(2147483648)?x:(x>(int64_t)t?(int32_t)t:(x<-(int64_t)t?-(int32_t)t:x));
  CHECK(out==expected);
  CHECK(pc_huber_clip_i32(out,t,&expected)&&expected==out);
 }
 return 0;
}
