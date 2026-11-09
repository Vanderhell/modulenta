#ifndef RM_ADC_OVERSAMPLE_ACCUMULATE_U32_H
#define RM_ADC_OVERSAMPLE_ACCUMULATE_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Add one ADC code to a caller-owned uint64 sum. Overflow/null fails atomically. */
bool rm_adc_oversample_accumulate_u32(uint32_t sample, uint64_t *sum);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_adc_oversample_accumulate_u32
#define pc_adc_oversample_accumulate_u32 rm_adc_oversample_accumulate_u32
#endif
#ifndef pc_adc_oversample_accumulate_u32
#define pc_adc_oversample_accumulate_u32 rm_adc_oversample_accumulate_u32
#endif
#ifndef PC_ADC_OVERSAMPLE_ACCUMULATE_U32_H
#define PC_ADC_OVERSAMPLE_ACCUMULATE_U32_H RM_ADC_OVERSAMPLE_ACCUMULATE_U32_H
#endif

