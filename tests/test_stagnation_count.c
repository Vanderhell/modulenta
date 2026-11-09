#include "../include/pc_opt_stagnation_count_u32.h"
#include <assert.h>
#include <stdint.h>

int main(void)
{
    uint32_t count = 0u;
    uint32_t i, latest_improvement = 0u;
    assert(pc_opt_stagnation_count_u32(&count, false) && count == 1u);
    assert(pc_opt_stagnation_count_u32(&count, false) && count == 2u);
    assert(pc_opt_stagnation_count_u32(&count, true) && count == 0u);
    count = UINT32_MAX - 1u;
    assert(pc_opt_stagnation_count_u32(&count, false) && count == UINT32_MAX);
    assert(pc_opt_stagnation_count_u32(&count, false) && count == UINT32_MAX);
    assert(pc_opt_stagnation_count_u32(&count, true) && count == 0u);
    for (i = 0u; i < 65536u; ++i) {
        count = i;
        assert(pc_opt_stagnation_count_u32(&count, true) && count == 0u);
        count = i;
        assert(pc_opt_stagnation_count_u32(&count, false) && count == i + 1u);
    }
    count = 0u;
    for (i = 0u; i < 1000000u; ++i) {
        const bool improved = (i % 997u) == 0u;
        assert(pc_opt_stagnation_count_u32(&count, improved));
        if (improved) latest_improvement = i;
        assert(count == i - latest_improvement);
    }
    count = UINT32_MAX - 1u;
    for (i = 0u; i < 1000000u; ++i)
        assert(pc_opt_stagnation_count_u32(&count, false));
    assert(count == UINT32_MAX);
    count = 42u;
    assert(!pc_opt_stagnation_count_u32(NULL, false) && count == 42u);
    assert(!pc_opt_stagnation_count_u32(NULL, true) && count == 42u);
    return 0;
}