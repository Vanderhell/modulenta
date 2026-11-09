#ifndef PRIMITIVECORE_BINARY_WIDTH_U32_H
#define PRIMITIVECORE_BINARY_WIDTH_U32_H
#include <stdint.h>

/* Return the number of significant binary digits; zero has width zero. */
uint8_t pc_binary_width_u32(uint32_t value);
#endif