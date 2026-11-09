#include "pc_rto_estimate_u32.h"

#include <stddef.h>
#include <stdint.h>

#define CHECK(condition) do { if (!(condition)) return __LINE__; } while (0)

int main(void)
{
    uint32_t rto = 77u;

    CHECK(pc_rto_estimate_u32(100u, 5u, 2u, 1u, 1000u, &rto));
    CHECK(rto == 120u);
    CHECK(pc_rto_estimate_u32(100u, 0u, 10u, 1u, 1000u, &rto));
    CHECK(rto == 110u);
    CHECK(pc_rto_estimate_u32(1u, 0u, 1u, 10u, 1000u, &rto));
    CHECK(rto == 10u);
    CHECK(pc_rto_estimate_u32(UINT32_MAX, UINT32_MAX, 1u, 1u,
                              UINT32_MAX, &rto));
    CHECK(rto == UINT32_MAX);

    rto = 77u;
    CHECK(!pc_rto_estimate_u32(1u, 1u, 0u, 1u, 9u, &rto) && rto == 77u);
    CHECK(!pc_rto_estimate_u32(1u, 1u, 1u, 0u, 9u, &rto) && rto == 77u);
    CHECK(!pc_rto_estimate_u32(1u, 1u, 1u, 10u, 9u, &rto) && rto == 77u);
    CHECK(!pc_rto_estimate_u32(1u, 1u, 1u, 1u, 9u, NULL));
    return 0;
}
