#ifndef PRIMITIVECORE_PC_MIDPOINT_U64_SAFE_H
#define PRIMITIVECORE_PC_MIDPOINT_U64_SAFE_H

#include <stdint.h>

/* Return floor((a+b)/2) without overflowing the uint64 domain. */
uint64_t pc_midpoint_u64_safe(uint64_t a, uint64_t b);

#endif