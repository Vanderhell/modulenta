#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "../include/second_max5.h"
static int32_t oracle(int32_t *v){for(int i=1;i<5;i++){int32_t x=v[i];int j=i;while(j>0&&v[j-1]>x){v[j]=v[j-1];--j;}v[j]=x;}return v[3];}
static uint32_t state=0x928af031u;
static uint32_t next(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
int main(void){const int32_t small[]={-2,-1,0,1};for(unsigned a=0;a<4;a++)for(unsigned b=0;b<4;b++)for(unsigned c=0;c<4;c++)for(unsigned d=0;d<4;d++)for(unsigned e=0;e<4;e++){int32_t v[]={small[a],small[b],small[c],small[d],small[e]},q[]={small[a],small[b],small[c],small[d],small[e]};if(pc_second_max5_i32_experiment(v[0],v[1],v[2],v[3],v[4])!=oracle(q))return 1;}
 const int32_t edge[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(unsigned a=0;a<7;a++)for(unsigned b=0;b<7;b++)for(unsigned c=0;c<7;c++)for(unsigned d=0;d<7;d++)for(unsigned e=0;e<7;e++){int32_t v[]={edge[a],edge[b],edge[c],edge[d],edge[e]},q[]={edge[a],edge[b],edge[c],edge[d],edge[e]};if(pc_second_max5_i32_experiment(v[0],v[1],v[2],v[3],v[4])!=oracle(q))return 2;}
 for(unsigned n=0;n<100000;n++){int32_t v[5],q[5];for(int i=0;i<5;i++){v[i]=(int32_t)next();q[i]=v[i];}if(pc_second_max5_i32_experiment(v[0],v[1],v[2],v[3],v[4])!=oracle(q))return 3;}puts("PASS: 1024 exhaustive + 16807 boundary + 100000 seeded full-width");return 0;}
