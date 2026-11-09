#include "../include/pc_anomaly_count_u32.h"
#include <assert.h>
#include <stdint.h>

int main(void)
{
    uint32_t count = 0u;
    uint32_t i;
    assert(pc_anomaly_count_u32(&count, false) && count == 0u);
    assert(pc_anomaly_count_u32(&count, true) && count == 1u);
    count = UINT32_MAX - 1u;
    assert(pc_anomaly_count_u32(&count, true) && count == UINT32_MAX);
    assert(pc_anomaly_count_u32(&count, true) && count == UINT32_MAX);
    assert(pc_anomaly_count_u32(&count, false) && count == UINT32_MAX);
    count = 0u;
    for (i = 0u; i < 65536u; ++i) {
        count = i;
        assert(pc_anomaly_count_u32(&count, true) && count == i + 1u);
        count = i;
        assert(pc_anomaly_count_u32(&count, false) && count == i);
    }
    count = 0u;
    for (i = 0u; i < 1000000u; ++i) {
        const bool event = ((i * 2654435761u) >> 28) == 0u;
        const uint32_t before = count;
        assert(pc_anomaly_count_u32(&count, event));
        if (event && before != UINT32_MAX) assert(count == before + 1u);
        else assert(count == before);
    }
    count = UINT32_MAX - 2u;
    for (i = 0u; i < 1000000u; ++i)
        assert(pc_anomaly_count_u32(&count, true));
    assert(count == UINT32_MAX);
    count = 123u;
    assert(!pc_anomaly_count_u32(NULL, false) && count == 123u);
    assert(!pc_anomaly_count_u32(NULL, true) && count == 123u);
    return 0;
}