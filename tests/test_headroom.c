#include <stdint.h>
#include <stdio.h>
#include "../include/u32_headroom.h"
#include "../oracle/oracle.h"
static uint32_t state=0x1038a55au;
static uint32_t next(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int check(uint32_t x){uint8_t h=pc_u32_headroom_experiment(x);if(h!=pc_u32_headroom_oracle_public(x))return 1;if(h<31u&&x<=(UINT32_MAX>>(h+1u)))return 2;return 0;}
int main(void){unsigned long long n=0;for(uint32_t x=0;x<=65535u;x++){if(check(x))return 1;n++;}const uint32_t e[]={0,1,2,3,UINT32_C(0x7fffffff),UINT32_C(0x80000000),UINT32_MAX-1u,UINT32_MAX};for(unsigned i=0;i<8;i++){if(check(e[i]))return 2;n++;}for(unsigned i=0;i<1000000;i++){if(check(next()))return 3;n++;}printf("PASS %llu exhaustive/boundary/seeded cases\n",n);return 0;}