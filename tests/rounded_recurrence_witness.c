#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
static uint32_t rng(uint32_t *s){*s^=*s<<13;*s^=*s>>17;*s^=*s<<5;return *s;}
static int32_t rounded_recurrence(int32_t center,uint32_t count,int32_t sample){int64_t n=(int64_t)center*count+sample,d=(int64_t)count+1,q=n/d,r=n%d;uint64_t a=(uint64_t)(r<0?-r:r);if(a*2u>(uint64_t)d||(a*2u==(uint64_t)d&&q%2!=0))q+=n<0?-1:1;return(int32_t)q;}
int main(void){uint32_t state=UINT32_C(0x4502),count=1u;int32_t sample,center;int64_t sum;unsigned i;sample=(int32_t)(rng(&state)%200001u)-100000;center=sample;sum=sample;
 for(i=1u;i<1000000u;i++){sample=(int32_t)(rng(&state)%200001u)-100000;center=rounded_recurrence(center,count,sample);sum+=sample;++count;}
 printf("steps=1000000 state=%" PRIu32 " center=%" PRId32 " sum=%" PRId64 " count=%" PRIu32 "\n",state,center,sum,count);return 0;}