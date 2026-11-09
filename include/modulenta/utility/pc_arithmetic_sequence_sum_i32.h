#ifndef RM_ARITHMETIC_SEQUENCE_SUM_I32_H
#define RM_ARITHMETIC_SEQUENCE_SUM_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Sum count terms start + i*step, i=0..count-1. Every term must fit int32.
 * Returns exact int64 sum; count zero returns zero. False leaves sum unchanged. */
bool rm_arithmetic_sequence_sum_i32(int32_t start, int32_t step, uint32_t count, int64_t *sum);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_arithmetic_sequence_sum_i32
#define pc_arithmetic_sequence_sum_i32 rm_arithmetic_sequence_sum_i32
#endif
#ifndef pc_arithmetic_sequence_sum_i32
#define pc_arithmetic_sequence_sum_i32 rm_arithmetic_sequence_sum_i32
#endif
#ifndef PC_ARITHMETIC_SEQUENCE_SUM_I32_H
#define PC_ARITHMETIC_SEQUENCE_SUM_I32_H RM_ARITHMETIC_SEQUENCE_SUM_I32_H
#endif

