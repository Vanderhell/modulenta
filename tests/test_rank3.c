#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "../include/rank3.h"
static uint32_t s=0xc3a5f117u;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static void oracle(int32_t a,int32_t b,int32_t c,uint8_t r[3]){int32_t v[]={a,b,c};uint8_t ix[]={0,1,2};for(int i=1;i<3;i++){uint8_t z=ix[i];int j=i;while(j&&(v[ix[j-1]]>v[z]||(v[ix[j-1]]==v[z]&&ix[j-1]>z))){ix[j]=ix[j-1];j--;}ix[j]=z;}for(uint8_t i=0;i<3;i++)r[ix[i]]=i;}
static int check(int32_t a,int32_t b,int32_t c){uint8_t x[3],y[3];pc_rank3_i32_experiment(a,b,c,x);oracle(a,b,c,y);return x[0]!=y[0]||x[1]!=y[1]||x[2]!=y[2];}
int main(void){const int32_t sm[]={-2,-1,0,1,2};for(int a=0;a<5;a++)for(int b=0;b<5;b++)for(int c=0;c<5;c++)if(check(sm[a],sm[b],sm[c]))return 1;const int32_t ed[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(int a=0;a<7;a++)for(int b=0;b<7;b++)for(int c=0;c<7;c++)if(check(ed[a],ed[b],ed[c]))return 2;for(unsigned i=0;i<100000;i++)if(check((int32_t)next(),(int32_t)next(),(int32_t)next()))return 3;puts("PASS: 125 exhaustive + 343 boundary + 100000 seeded");return 0;}
