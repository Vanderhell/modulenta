#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "../include/monotonic_dec_i32.h"
/* Held-out cross-family validation source; dependency is outside this product. */
static int reference(const int32_t*a,size_t n){if(a==NULL)return n==0u;for(size_t i=1;i<n;i++)if(a[i-1]<a[i])return 0;return 1;}
static int matches(const int32_t *a,size_t n){int expected=reference(a,n);return (int)pc_is_monotonic_dec_i32_experiment(a,n)==expected&&(int)pc_is_monotonic_dec_i32(a,n)==expected;}
static uint32_t state=UINT32_C(0x1102a55a);
static uint32_t next_u32(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
int main(void){int32_t a[64];unsigned long long cases=0;
for(size_t n=0;n<=5;n++){uint32_t total=1u;for(size_t i=0;i<n;i++)total*=5u;for(uint32_t c=0;c<total;c++){uint32_t v=c;for(size_t i=0;i<n;i++){a[i]=(int32_t)(v%5u)-2;v/=5u;}if(!matches(n?a:NULL,n))return 1;cases++;}}
const int32_t e[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};for(size_t i=0;i<7;i++)for(size_t j=0;j<7;j++){a[0]=e[i];a[1]=e[j];if(!matches(a,2))return 2;cases++;}
if(!matches(NULL,0u)||!matches(NULL,1u))return 3;
for(unsigned k=0;k<100000u;k++){size_t n=next_u32()%65u;for(size_t i=0;i<n;i++)a[i]=(int32_t)next_u32();if(!matches(n?a:NULL,n))return 4;cases++;}
printf("PASS descending relation over %llu arrays\n",cases);return 0;}