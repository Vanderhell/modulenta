#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "../include/rank5.h"
static uint32_t s=0x14f273a9u;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static void oracle(int32_t*v,uint8_t*r){uint8_t ix[]={0,1,2,3,4};for(int i=1;i<5;i++){uint8_t z=ix[i];int j=i;while(j&&(v[ix[j-1]]>v[z]||(v[ix[j-1]]==v[z]&&ix[j-1]>z))){ix[j]=ix[j-1];j--;}ix[j]=z;}for(uint8_t i=0;i<5;i++)r[ix[i]]=i;}
static int check(int32_t*v){uint8_t a[5],b[5];pc_rank5_i32_experiment(v[0],v[1],v[2],v[3],v[4],a);oracle(v,b);for(int i=0;i<5;i++)if(a[i]!=b[i])return 1;return 0;}
int main(void){const int32_t sm[]={-1,0,1};for(int a=0;a<3;a++)for(int b=0;b<3;b++)for(int c=0;c<3;c++)for(int d=0;d<3;d++)for(int e=0;e<3;e++){int32_t v[]={sm[a],sm[b],sm[c],sm[d],sm[e]};if(check(v))return 1;}const int32_t ed[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(int a=0;a<7;a++)for(int b=0;b<7;b++)for(int c=0;c<7;c++)for(int d=0;d<7;d++)for(int e=0;e<7;e++){int32_t v[]={ed[a],ed[b],ed[c],ed[d],ed[e]};if(check(v))return 2;}for(unsigned k=0;k<100000;k++){int32_t v[5];for(int i=0;i<5;i++)v[i]=(int32_t)next();if(check(v))return 3;}puts("PASS: 243 exhaustive + 16807 boundary + 100000 seeded");return 0;}