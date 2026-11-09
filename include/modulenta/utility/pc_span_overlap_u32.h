#ifndef PC_SPAN_OVERLAP_U32_H
#define PC_SPAN_OVERLAP_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Test overlap of two valid half-open spans; empty/overflowing spans do not overlap. */
bool pc_span_overlap_u32(uint32_t a_start, uint32_t a_length,
                         uint32_t b_start, uint32_t b_length);

#endif