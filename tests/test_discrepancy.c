#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
bool pc_onewire_search_discrepancy_u32(uint32_t, uint32_t, uint32_t, uint32_t *);

static uint32_t oracle(uint32_t bit, uint32_t last, uint32_t old_rom)
{
    if (bit < last) return old_rom;
    if (bit == last) return 1u;
    return 0u;
}

int main(void)
{
    uint32_t bit, last, old;
    for (bit = 1u; bit <= 64u; ++bit) {
        for (last = 0u; last <= 64u; ++last) {
            for (old = 0u; old <= 1u; ++old) {
                uint32_t out = UINT32_C(0xA5);
                assert(pc_onewire_search_discrepancy_u32(bit,last,old,&out));
                assert(out == oracle(bit,last,old));
            }
        }
    }
    {
        const uint32_t invalid[][3] = {{0u,0u,0u},{65u,0u,0u},{1u,65u,0u},{1u,0u,2u}};
        unsigned i;
        for (i=0u;i<4u;++i) {
            uint32_t out=UINT32_C(0x5A);
            assert(!pc_onewire_search_discrepancy_u32(invalid[i][0],invalid[i][1],invalid[i][2],&out));
            assert(out==UINT32_C(0x5A));
        }
        assert(!pc_onewire_search_discrepancy_u32(1u,0u,0u,NULL));
    }
    return 0;
}
