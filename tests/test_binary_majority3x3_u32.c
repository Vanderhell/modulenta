#include "pc_binary_majority3x3_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void){uint32_t m,out=77u;for(m=0;m<512u;++m){uint32_t n=m,c=0;while(n){c+=n&1u;n>>=1u;}CHECK(pc_binary_majority3x3_u32(m,&out));CHECK(out==(uint32_t)(c>=UINT32_C(5)));}
out=77u;CHECK(!pc_binary_majority3x3_u32(512u,&out)&&out==77u);out=77u;CHECK(!pc_binary_majority3x3_u32(UINT32_MAX,&out)&&out==77u);CHECK(!pc_binary_majority3x3_u32(0u,NULL));puts("pc_binary_majority3x3_u32 experiment: PASS (512 masks)");return 0;}
