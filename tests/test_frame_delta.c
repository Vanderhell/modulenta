#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

bool pc_usb_frame_number_delta_u32(uint32_t previous, uint32_t current,
                                   uint32_t *delta);

int main(void)
{
    uint32_t previous,current;
    for(previous=0u;previous<2048u;++previous) for(current=0u;current<2048u;++current) {
        uint32_t actual=UINT32_C(0xA5);
        uint32_t expected=(current+2048u-previous)%2048u;
        assert(pc_usb_frame_number_delta_u32(previous,current,&actual));
        assert(actual==expected);
    }
    {
        uint32_t out=0x5Au;
        assert(!pc_usb_frame_number_delta_u32(2048u,0u,&out)&&out==0x5Au);
        assert(!pc_usb_frame_number_delta_u32(0u,2048u,&out)&&out==0x5Au);
        assert(!pc_usb_frame_number_delta_u32(UINT32_MAX,0u,&out)&&out==0x5Au);
        assert(!pc_usb_frame_number_delta_u32(0u,0u,NULL));
    }
    return 0;
}
