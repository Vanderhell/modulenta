#include <inttypes.h>
#include <stdio.h>
#include "../include/pc_onewire_crc8_step_u32.c"
int main(void) {
    for(uint32_t crc=0;crc<256u;++crc) for(uint32_t b=0;b<256u;++b) {
        uint32_t out=0u;
        if(!pc_onewire_crc8_step_u32(crc,b,&out)) return 1;
        printf("%02" PRIx32 "\n",out);
    }
    return 0;
}
