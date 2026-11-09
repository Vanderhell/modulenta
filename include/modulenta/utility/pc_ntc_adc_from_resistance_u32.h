#ifndef PC_NTC_ADC_FROM_RESISTANCE_U32_H
#define PC_NTC_ADC_FROM_RESISTANCE_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Ratiometric divider: fixed resistor to excitation, NTC to ground, ADC at
 * midpoint. adc_full_scale is maximum code (not 2^N). Output code is rounded
 * nearest-even and may equal full-scale for a finite high resistance. */
bool pc_ntc_adc_from_resistance_u32(uint32_t ntc_resistance_ohm,
                                    uint32_t fixed_resistor_ohm,
                                    uint32_t adc_full_scale,
                                    uint32_t *adc_code);
#endif
