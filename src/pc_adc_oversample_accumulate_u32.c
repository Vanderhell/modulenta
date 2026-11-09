#include "pc_adc_oversample_accumulate_u32.h"
#include <stddef.h>
bool rm_adc_oversample_accumulate_u32(uint32_t sample, uint64_t *sum)
{
    if (sum == NULL || UINT64_MAX - *sum < sample) return false;
    *sum += sample;
    return true;
}