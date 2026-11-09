#ifndef PRIMITIVECORE_PC_BINARY_MAJORITY3X3_U32_H
#define PRIMITIVECORE_PC_BINARY_MAJORITY3X3_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Low 9 bits encode a complete 3x3 neighborhood, row-major; output is 0/1.
 * False for high bits or null result; failure preserves *result. */
bool pc_binary_majority3x3_u32(uint32_t neighborhood, uint32_t *result);
#endif
