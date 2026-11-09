#include "pc_ble_hop_step_u32.h"
#include <assert.h>
#include <stdint.h>

int main(void)
{
    uint32_t last;
    uint32_t hop;
    uint32_t result = UINT32_C(0xA5A5A5A5);
    for (last = 0u; last < 37u; ++last) {
        for (hop = 5u; hop <= 16u; ++hop) {
            assert(pc_ble_hop_step_u32(last, hop, &result));
            assert(result == (last + hop) % 37u);
        }
    }
    assert(pc_ble_hop_step_u32(36u, 5u, &result) && result == 4u);
    result = UINT32_C(0xA5A5A5A5);
    assert(!pc_ble_hop_step_u32(37u, 5u, &result));
    assert(result == UINT32_C(0xA5A5A5A5));
    assert(!pc_ble_hop_step_u32(0u, 4u, &result));
    assert(!pc_ble_hop_step_u32(0u, 17u, &result));
    assert(!pc_ble_hop_step_u32(0u, 5u, NULL));
    return 0;
}