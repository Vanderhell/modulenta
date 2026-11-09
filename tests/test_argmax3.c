#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "../include/argmax3.h"
static uint32_t s=0x7b891e2du;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static uint8_t oracle(int32_t a,int32_t b,int32_t c){int32_t m=a>b?a:b;if(c>m)m=c;if(a==m)return 0;if(b==m)return 1;return 2;}
int main(void){const int32_t v[]={-2,-1,0,1};for(unsigned a=0;a<4;a++)for(unsigned b=0;b<4;b++)for(unsigned c=0;c<4;c++)if(pc_argmax3_i32_experiment(v[a],v[b],v[c])!=oracle(v[a],v[b],v[c]))return 1;const int32_t e[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(unsigned a=0;a<7;a++)for(unsigned b=0;b<7;b++)for(unsigned c=0;c<7;c++)if(pc_argmax3_i32_experiment(e[a],e[b],e[c])!=oracle(e[a],e[b],e[c]))return 2;for(unsigned i=0;i<100000;i++){int32_t a=(int32_t)next(),b=(int32_t)next(),c=(int32_t)next();if(pc_argmax3_i32_experiment(a,b,c)!=oracle(a,b,c))return 3;}puts("PASS: 64 exhaustive + 343 boundary + 100000 seeded");return 0;}
