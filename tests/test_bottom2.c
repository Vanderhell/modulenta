#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "../include/bottom2.h"
static uint32_t s=0x149f8a63u;static uint32_t next(void){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
static void ref(int32_t *v,size_t n,int32_t *a,int32_t *b){for(size_t i=1;i<n;i++){int32_t x=v[i];size_t j=i;while(j&&v[j-1]>x){v[j]=v[j-1];j--;}v[j]=x;}*a=v[0];*b=v[1];}
static int check(int32_t*v,size_t n){int32_t q[8],a,b,x=22,y=33;for(size_t i=0;i<n;i++)q[i]=v[i];ref(q,n,&a,&b);return !pc_bottom2_i32_experiment(v,n,&x,&y)||x!=a||y!=b;}
int main(void){const int32_t sm[]={-2,-1,0,1};unsigned total=0;for(size_t n=2;n<=6;n++){size_t lim=1;for(size_t i=0;i<n;i++)lim*=4;for(size_t code=0;code<lim;code++){size_t z=code;int32_t v[8];for(size_t i=0;i<n;i++){v[i]=sm[z%4];z/=4;}if(check(v,n))return 1;total++;}}const int32_t ed[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(unsigned a=0;a<7;a++)for(unsigned b=0;b<7;b++)for(unsigned c=0;c<7;c++)for(unsigned e=0;e<7;e++){int32_t v[]={ed[a],ed[b],ed[c],ed[e]};if(check(v,4))return 2;}for(unsigned k=0;k<100000;k++){size_t n=2+next()%7;int32_t v[8];for(size_t i=0;i<n;i++)v[i]=(int32_t)next();if(check(v,n))return 3;}int32_t o=4,p=5,v[]={0,1};if(pc_bottom2_i32_experiment(NULL,2,&o,&p)||o!=4||p!=5)return 4;if(pc_bottom2_i32_experiment(v,1,&o,&p)||o!=4||p!=5)return 5;if(pc_bottom2_i32_experiment(v,2,&o,&o)||o!=4)return 6;printf("PASS: %u exhaustive + 2401 boundary + 100000 seeded + invalid transaction\n",total);return 0;}
