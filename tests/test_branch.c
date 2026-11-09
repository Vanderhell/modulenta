/* Held-out cross-family validation source; dependency is outside this product. */
#include <assert.h>
#include <stdint.h>

static bool oracle(uint32_t id, uint32_t complement, uint32_t preferred,
                   uint32_t *direction)
{
    if (id > 1u || complement > 1u || preferred > 1u || (id == 1u && complement == 1u)) return false;
    if (id == 0u && complement == 0u) *direction = preferred;
    else if (id == 1u && complement == 0u) *direction = 1u;
    else *direction = 0u;
    return true;
}

int main(void)
{
    uint32_t id, complement, preferred;
    for (id = 0u; id <= 1u; ++id) {
        for (complement = 0u; complement <= 1u; ++complement) {
            for (preferred = 0u; preferred <= 1u; ++preferred) {
                uint32_t expected = 0xA5u, actual = expected;
                bool expect_ok = oracle(id, complement, preferred, &expected);
                bool actual_ok = pc_onewire_search_branch_u32(id, complement, preferred, &actual);
                assert(actual_ok == expect_ok);
                assert(actual == expected);
            }
        }
    }
    for (id = 2u; id < 4u; ++id) {
        uint32_t actual = 0x5Au;
        assert(!pc_onewire_search_branch_u32(id, 0u, 0u, &actual));
        assert(actual == 0x5Au);
        assert(!pc_onewire_search_branch_u32(0u, id, 0u, &actual));
        assert(actual == 0x5Au);
        assert(!pc_onewire_search_branch_u32(0u, 1u, id, &actual));
        assert(actual == 0x5Au);
    }
    {
        uint32_t actual = 0x5Au;
        assert(!pc_onewire_search_branch_u32(1u, 1u, 0u, &actual));
        assert(actual == 0x5Au);
    }
    assert(!pc_onewire_search_branch_u32(1u, 1u, 0u, &(uint32_t){0u}));
    assert(!pc_onewire_search_branch_u32(0u, 0u, 0u, NULL));
    return 0;
}