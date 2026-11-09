#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "pc_cluster_update_center_i32.h"
static uint32_t rng(uint32_t *s){*s^=*s<<13;*s^=*s>>17;*s^=*s<<5;return *s;}
int main(void){uint32_t state=UINT32_C(0x4502),count=0u;int32_t sample,center=0;int64_t sum=0;unsigned i;
 for(i=0;i<1000000u;i++){sample=(int32_t)(rng(&state)%200001u)-100000;if(!pc_cluster_update_center_i32(sample,&sum,&count,&center))return 2;}
 printf("steps=1000000 state=%" PRIu32 " sum=%" PRId64 " count=%" PRIu32 " center=%" PRId32 "\n",state,sum,count,center);return 0;}
