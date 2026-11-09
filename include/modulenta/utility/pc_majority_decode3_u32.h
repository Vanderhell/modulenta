#ifndef PRIMITIVECORE_MAJORITY_DECODE3_U32_H
#define PRIMITIVECORE_MAJORITY_DECODE3_U32_H

#include <stdint.h>

/* Bitwise majority vote among three redundant uint32_t replicas.
 * This is not a numerical median and does not report disagreement. */
uint32_t pc_majority_decode3_u32(uint32_t a, uint32_t b, uint32_t c);

#endif
