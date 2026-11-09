#include <assert.h>
#include <stdint.h>
#include "../include/pc_onewire_crc8_step_u32.c"
int main(void) {
    uint32_t out=0u;
    for (uint32_t crc=0; crc<=255u; ++crc) {
        for (uint32_t b=0; b<=255u; ++b) {
            uint8_t v=(uint8_t)(crc^b);
            for (unsigned bit=0; bit<8u; ++bit) {
                v=(uint8_t)((v&1u)?((v>>1u)^0x8Cu):(v>>1u));
            }
            assert(pc_onewire_crc8_step_u32(crc,b,&out) && out==v);
        }
    }
    out=0u;
    for (const unsigned char *p=(const unsigned char *)"123456789"; *p; ++p) {
        assert(pc_onewire_crc8_step_u32(out,(uint32_t)*p,&out));
    }
    assert(out==0xA1u);
    out=0xA5u;
    assert(!pc_onewire_crc8_step_u32(256u,0u,&out) && out==0xA5u);
    assert(!pc_onewire_crc8_step_u32(0u,256u,&out) && out==0xA5u);
    assert(!pc_onewire_crc8_step_u32(0u,0u,0));
    return 0;
}