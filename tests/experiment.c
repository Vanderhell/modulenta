#include <stdint.h>
#include <stdio.h>
#include "../include/pc_ring_contiguous_read_u32.h"
int main(void){for(uint32_t n=1;n<=128;n++)for(uint32_t t=0;t<n;t++)for(uint32_t u=0;u<=n;u++){uint32_t span=UINT32_MAX,expected=u<n-t?u:n-t;if(!pc_ring_contiguous_read_u32(t,u,n,&span)||span!=expected||span>u||span>n-t)return 1;}uint32_t span=77;if(pc_ring_contiguous_read_u32(0,0,0,&span)||span!=77||pc_ring_contiguous_read_u32(4,0,4,&span)||span!=77||pc_ring_contiguous_read_u32(0,5,4,&span)||span!=77||pc_ring_contiguous_read_u32(0,0,1,NULL))return 2;puts("all tail/used tuples for capacity 1..128; empty/full/end and invalid preservation PASS");}
