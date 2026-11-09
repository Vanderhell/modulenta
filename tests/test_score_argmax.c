#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "../include/score_argmax.h"
static uint32_t s=0x19a7c305u;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static size_t oracle(int32_t*v,size_t n){size_t k=0;for(size_t i=1;i<n;i++)if(v[i]>v[k])k=i;return k;}
static int check(int32_t*v,size_t n){size_t x=99,y=oracle(v,n);return !pc_score_argmax_i32_experiment(v,n,&x)||x!=y;}
int main(void){const int32_t sm[]={-1,0,1};for(size_t n=1;n<=7;n++){size_t lim=1;for(size_t i=0;i<n;i++)lim*=3;for(size_t z=0;z<lim;z++){size_t q=z;int32_t v[8];for(size_t i=0;i<n;i++){v[i]=sm[q%3];q/=3;}if(check(v,n))return 1;}}const int32_t ed[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(unsigned a=0;a<7;a++)for(unsigned b=0;b<7;b++)for(unsigned c=0;c<7;c++)for(unsigned d=0;d<7;d++){int32_t v[]={ed[a],ed[b],ed[c],ed[d]};if(check(v,4))return 2;}for(unsigned t=0;t<100000;t++){size_t n=1+next()%8;int32_t v[8];for(size_t i=0;i<n;i++)v[i]=(int32_t)next();if(check(v,n))return 3;}size_t o=66;int32_t v[]={1};if(pc_score_argmax_i32_experiment(NULL,1,&o)||o!=66)return 4;if(pc_score_argmax_i32_experiment(v,0,&o)||o!=66)return 5;if(pc_score_argmax_i32_experiment(v,1,NULL))return 6;puts("PASS: 3279 exhaustive arrays + 2401 boundary + 100000 seeded + invalids");return 0;}
