#include "pc_led_fade_step_u8.h"
#include <assert.h>
#include <stdint.h>
int main(void){uint32_t i;uint8_t x=0u;for(i=0;i<255u;i++){uint8_t y=pc_led_fade_step_u8(x,255u,1u);assert(y==x+1u);x=y;}assert(x==255u);for(i=0;i<100000u;i++){uint8_t target=(i&1u)?0u:255u,old=x;x=pc_led_fade_step_u8(x,target,7u);assert(target>=old?x>=old&&x<=target:x<=old&&x>=target);}return 0;}
