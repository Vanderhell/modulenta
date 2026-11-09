#include "pc_binary_run_vertical_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do{if(!(x))return __LINE__;}while(0)
static uint32_t state=UINT32_C(0x3512a11c);
static uint32_t next(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
int main(void){uint8_t im[64];uint32_t w,h,x,y,out,expect;unsigned i,j;
for(h=1;h<=3u;++h)for(w=1;w<=3u;++w)for(i=0;i<(1u<<(w*h));++i){for(j=0;j<w*h;++j)im[j]=(uint8_t)((i>>j)&1u);for(x=0;x<w;++x)for(y=0;y<=h;++y){expect=0;while(y+expect<h&&im[(y+expect)*w+x])++expect;CHECK(pc_binary_run_vertical_u32(im,w,h,x,y,&out)&&out==expect);}}
for(i=0;i<10000u;++i){w=1u+next()%8u;h=1u+next()%8u;for(j=0;j<w*h;++j)im[j]=(uint8_t)(next()&1u);x=next()%w;y=next()%(h+1u);expect=0;while(y+expect<h&&im[(y+expect)*w+x])++expect;CHECK(pc_binary_run_vertical_u32(im,w,h,x,y,&out)&&out==expect);}
out=77u;CHECK(!pc_binary_run_vertical_u32(NULL,1u,1u,0u,0u,&out)&&out==77u);CHECK(!pc_binary_run_vertical_u32(im,0u,1u,0u,0u,&out)&&out==77u);CHECK(!pc_binary_run_vertical_u32(im,1u,1u,1u,0u,&out)&&out==77u);CHECK(!pc_binary_run_vertical_u32(im,1u,1u,0u,2u,&out)&&out==77u);CHECK(!pc_binary_run_vertical_u32(im,1u,1u,0u,0u,NULL));puts("pc_binary_run_vertical_u32 experiment: PASS (through 3x3 exhaustive, 10,000 seeded)");return 0;}
