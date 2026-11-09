#include "primitivecore/fixed_point/conversion/q/pc_ntc_adc_from_resistance_u32.h"
#include <stddef.h>

static uint64_t divide_round_even_u64(uint64_t numerator, uint64_t denominator)
{
    uint64_t quotient = numerator / denominator;
    uint64_t remainder = numerator % denominator;
    if (remainder > denominator - remainder ||
        (remainder == denominator - remainder && (quotient & UINT64_C(1)) != 0u)) {
        ++quotient;
    }
    return quotient;
}

bool pc_ntc_adc_from_resistance_u32(uint32_t ntc_resistance_ohm,
                                    uint32_t fixed_resistor_ohm,
                                    uint32_t adc_full_scale,
                                    uint32_t *adc_code)
{
    uint64_t numerator, denominator, rounded;
    if (adc_code == NULL || fixed_resistor_ohm == 0u || adc_full_scale == 0u)
        return false;
    numerator = (uint64_t)adc_full_scale * ntc_resistance_ohm;
    denominator = (uint64_t)fixed_resistor_ohm + ntc_resistance_ohm;
    rounded = divide_round_even_u64(numerator, denominator);
    if (rounded > adc_full_scale) return false;
    *adc_code = (uint32_t)rounded;
    return true;
}
