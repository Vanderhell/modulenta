#include "pc_led_fade_step_u8.h"
#include <assert.h>
#include <stdint.h>
static uint8_t oracle(uint32_t c,uint32_t t,uint32_t s){if(c<t){uint32_t v=c+s;return(uint8_t)(v<t?v:t);}if(c>t){return(uint8_t)(c-t>s?c-s:t);}return(uint8_t)c;}
int main(void){uint32_t c,t,s;for(c=0;c<256u;c++)for(t=0;t<256u;t++)for(s=0;s<256u;s++){uint8_t out=pc_led_fade_step_u8((uint8_t)c,(uint8_t)t,(uint8_t)s);assert(out==oracle(c,t,s));assert(out>= (c<t?c:t)&&out<= (c>t?c:t));}return 0;}
