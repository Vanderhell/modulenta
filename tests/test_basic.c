#include <stdint.h>
#include <stdio.h>
#include "pc_ntc_lookup_adc_u32.h"

int main(void)
{
    uint32_t out;
    const pc_ntc_adc_point_u32 even[] = {{0, 1u}, {2, 0u}};
    const pc_ntc_adc_point_u32 odd[] = {{0, 3u}, {2, 0u}};
    const pc_ntc_adc_point_u32 full[] = {{INT32_MIN, UINT32_MAX},
                                         {INT32_MAX, 0u}};
    const pc_ntc_adc_point_u32 invalid_t[] = {{1, 10u}, {1, 0u}};
    const pc_ntc_adc_point_u32 invalid_adc[] = {{0, 0u}, {1, 1u}};
    if (!pc_ntc_lookup_adc_u32(even, 2u, 1, &out) || out != 0u ||
        !pc_ntc_lookup_adc_u32(odd, 2u, 1, &out) || out != 2u ||
        !pc_ntc_lookup_adc_u32(full, 2u, 0, &out) || out != UINT32_C(0x7FFFFFFF) ||
        !pc_ntc_lookup_adc_u32(full, 2u, INT32_MIN, &out) || out != UINT32_MAX ||
        !pc_ntc_lookup_adc_u32(full, 2u, INT32_MAX, &out) || out != 0u)
        return 1;
    out = 123u;
    if (pc_ntc_lookup_adc_u32(invalid_t, 2u, 1, &out) || out != 123u ||
        pc_ntc_lookup_adc_u32(invalid_adc, 2u, 0, &out) || out != 123u ||
        pc_ntc_lookup_adc_u32(full, 1u, 0, &out) || out != 123u ||
        pc_ntc_lookup_adc_u32(full, 2u, 0, NULL)) return 2;
    puts("NTC inverse ADC lookup full range, ties, and invalid-table cases PASS");
    return 0;
}
