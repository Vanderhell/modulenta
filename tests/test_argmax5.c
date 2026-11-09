#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "../include/argmax5.h"
static uint32_t s=0xb312a5d7u;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static uint8_t oracle(int32_t *v){int32_t m=v[0];for(int i=1;i<5;i++)if(v[i]>m)m=v[i];for(uint8_t i=0;i<5;i++)if(v[i]==m)return i;return 0;}
int main(void){const int32_t sm[]={-2,-1,0,1};for(unsigned a=0;a<4;a++)for(unsigned b=0;b<4;b++)for(unsigned c=0;c<4;c++)for(unsigned d=0;d<4;d++)for(unsigned e=0;e<4;e++){int32_t v[]={sm[a],sm[b],sm[c],sm[d],sm[e]};if(pc_argmax5_i32_experiment(v[0],v[1],v[2],v[3],v[4])!=oracle(v))return 1;}const int32_t ed[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(unsigned a=0;a<7;a++)for(unsigned b=0;b<7;b++)for(unsigned c=0;c<7;c++)for(unsigned d=0;d<7;d++)for(unsigned e=0;e<7;e++){int32_t v[]={ed[a],ed[b],ed[c],ed[d],ed[e]};if(pc_argmax5_i32_experiment(v[0],v[1],v[2],v[3],v[4])!=oracle(v))return 2;}for(unsigned n=0;n<100000;n++){int32_t v[5];for(int i=0;i<5;i++)v[i]=(int32_t)next();if(pc_argmax5_i32_experiment(v[0],v[1],v[2],v[3],v[4])!=oracle(v))return 3;}puts("PASS: 1024 exhaustive + 16807 boundary + 100000 seeded");return 0;}
