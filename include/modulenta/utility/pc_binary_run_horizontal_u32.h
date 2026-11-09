#ifndef PRIMITIVECORE_PC_BINARY_RUN_HORIZONTAL_U32_H
#define PRIMITIVECORE_PC_BINARY_RUN_HORIZONTAL_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Count consecutive nonzero row samples from start_x to the first zero or width.
 * start_x==width returns zero. Invalid arguments preserve *run_length. */
bool pc_binary_run_horizontal_u32(const uint8_t *row, uint32_t width,
                                  uint32_t start_x, uint32_t *run_length);
#endif