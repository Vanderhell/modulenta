#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "frame_seq_gap.h"
static uint32_t state=0xB16B00B5u;static uint32_t next(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static void emit(uint32_t a,uint32_t b){uint32_t q=0;int ok=pc_frame_seq_gap_experiment(a,b,&q);printf("%" PRIu32 " %" PRIu32 " %d %" PRIu32 "\n",a,b,ok?1:0,q);}
int main(void){emit(10,13);emit(10,11);emit(UINT32_MAX,0);emit(UINT32_MAX-1u,1);emit(0,0);emit(1,0);emit(0,UINT32_C(0x7fffffff));emit(0,UINT32_C(0x80000000));emit(0,UINT32_C(0x80000001));emit(0,UINT32_MAX);for(unsigned i=0;i<10000u;++i)emit(next(),next());return 0;}
