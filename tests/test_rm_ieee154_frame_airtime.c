#include "pc_ieee154_frame_airtime_u32.h"
#include <assert.h>
#include <stdint.h>

int main(void)
{
    uint32_t n;
    uint32_t us = UINT32_C(0xA5A5A5A5);
    for (n = 0u; n <= 127u; ++n) {
        assert(pc_ieee154_frame_airtime_u32(n, &us));
        assert(us == 192u + 32u * n);
    }
    us = UINT32_C(0xA5A5A5A5);
    assert(!pc_ieee154_frame_airtime_u32(128u, &us));
    assert(us == UINT32_C(0xA5A5A5A5));
    assert(!pc_ieee154_frame_airtime_u32(0u, NULL));
    return 0;
}
