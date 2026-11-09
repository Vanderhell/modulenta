#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "../include/farthest3.h"
static uint32_t s=0x291c3da7u;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static uint32_t mag(int32_t x){return x<0?(uint32_t)(-(int64_t)x):(uint32_t)x;}
static int32_t oracle(int32_t a,int32_t b,int32_t c){uint32_t x=mag(a),y=mag(b),z=mag(c);int32_t r=a;uint32_t m=x;if(y>m){r=b;m=y;}if(z>m)r=c;return r;}
int main(void){for(int a=-128;a<128;a++)for(int b=-128;b<128;b++)for(int c=-128;c<128;c++)if(pc_farthest_of3_i32_experiment(a,b,c)!=oracle(a,b,c))return 1;const int32_t e[]={INT32_MIN,INT32_MIN+1,-2,-1,0,1,2,INT32_MAX-1,INT32_MAX};for(unsigned a=0;a<9;a++)for(unsigned b=0;b<9;b++)for(unsigned c=0;c<9;c++)if(pc_farthest_of3_i32_experiment(e[a],e[b],e[c])!=oracle(e[a],e[b],e[c]))return 2;for(unsigned i=0;i<100000;i++){int32_t a=(int32_t)next(),b=(int32_t)next(),c=(int32_t)next();if(pc_farthest_of3_i32_experiment(a,b,c)!=oracle(a,b,c))return 3;}puts("PASS: 16777216 int8 + 729 boundary + 100000 seeded");return 0;}
