#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

bool pc_usb_endpoint_interval_u32(uint32_t speed, uint32_t endpoint_type,
                                  uint32_t b_interval, uint32_t *interval_us);

static bool oracle(uint32_t speed,uint32_t type,uint32_t bi,uint32_t *out)
{
    if (bi>255u) return false;
    if (speed==1u && type==1u) { if(bi<10u)return false; *out=bi*1000u; return true; }
    if (speed==2u && type==1u) { if(bi<1u)return false; *out=bi*1000u; return true; }
    if (speed==2u && type==2u) { if(bi<1u||bi>16u)return false; *out=(UINT32_C(1)<<(bi-1u))*1000u; return true; }
    if (speed==3u && (type==1u||type==2u)) { if(bi<1u||bi>16u)return false; *out=(UINT32_C(1)<<(bi-1u))*125u; return true; }
    return false;
}

int main(void)
{
    uint32_t speed,type,bi;
    for(speed=0u;speed<=4u;++speed) for(type=0u;type<=3u;++type) for(bi=0u;bi<=255u;++bi) {
        uint32_t expected=0xA5u,actual=expected;
        bool eo=oracle(speed,type,bi,&expected);
        bool ao=pc_usb_endpoint_interval_u32(speed,type,bi,&actual);
        assert(eo==ao);
        assert(expected==actual);
    }
    {
        uint32_t out=0x5Au;
        assert(!pc_usb_endpoint_interval_u32(2u,1u,0u,&out)&&out==0x5Au);
        assert(!pc_usb_endpoint_interval_u32(2u,2u,17u,&out)&&out==0x5Au);
        assert(!pc_usb_endpoint_interval_u32(3u,1u,17u,&out)&&out==0x5Au);
        assert(!pc_usb_endpoint_interval_u32(1u,1u,9u,&out)&&out==0x5Au);
        assert(!pc_usb_endpoint_interval_u32(1u,2u,10u,&out)&&out==0x5Au);
        assert(!pc_usb_endpoint_interval_u32(4u,1u,1u,&out)&&out==0x5Au);
        assert(!pc_usb_endpoint_interval_u32(2u,1u,1u,NULL));
    }
    return 0;
}