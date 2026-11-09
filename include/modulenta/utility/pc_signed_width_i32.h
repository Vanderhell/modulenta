#ifndef PRIMITIVECORE_SIGNED_WIDTH_I32_H
#define PRIMITIVECORE_SIGNED_WIDTH_I32_H
#include <stdint.h>

/* Minimum two's-complement bit count including sign; zero requires one bit. */
uint8_t pc_signed_width_i32(int32_t value);
#endif
