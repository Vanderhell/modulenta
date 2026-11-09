#ifndef PC_PC_BSWAP64_U64_H
#define PC_PC_BSWAP64_U64_H
#include <stdint.h>

/* Reverse the eight byte positions in a uint64 value. */
uint64_t pc_bswap64_u64(uint64_t value);

#endif