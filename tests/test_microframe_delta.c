#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
bool pc_usb_microframe_delta_u32(uint32_t,uint32_t,uint32_t *);

static uint32_t oracle(uint32_t previous,uint32_t current)
{
    return (uint32_t)(((uint64_t)current+UINT64_C(16384)-previous)%UINT64_C(16384));
}

int main(void)
{
    const uint32_t starts[]={0u,1u,8191u,16383u};
    unsigned s;
    uint32_t delta;
    for(s=0u;s<4u;++s) for(delta=0u;delta<16384u;++delta) {
        uint32_t previous=starts[s];
        uint32_t current=(previous+delta)&UINT32_C(0x3FFF);
        uint32_t actual=UINT32_C(0xA5);
        assert(pc_usb_microframe_delta_u32(previous,current,&actual));
        assert(actual==oracle(previous,current));
        assert(actual==delta);
    }
    {
        uint32_t state=UINT32_C(0x3125C0DE);
        unsigned i;
        for(i=0u;i<1000000u;++i) {
            uint32_t previous,current,actual=0u;
            state=state*UINT32_C(1664525)+UINT32_C(1013904223); previous=state&UINT32_C(0x3FFF);
            state=state*UINT32_C(1664525)+UINT32_C(1013904223); current=state&UINT32_C(0x3FFF);
            assert(pc_usb_microframe_delta_u32(previous,current,&actual));
            assert(actual==oracle(previous,current));
        }
    }
    {
        uint32_t out=UINT32_C(0x5A);
        assert(!pc_usb_microframe_delta_u32(16384u,0u,&out)&&out==0x5Au);
        assert(!pc_usb_microframe_delta_u32(0u,16384u,&out)&&out==0x5Au);
        assert(!pc_usb_microframe_delta_u32(UINT32_MAX,0u,&out)&&out==0x5Au);
        assert(!pc_usb_microframe_delta_u32(0u,0u,NULL));
    }
    return 0;
}
