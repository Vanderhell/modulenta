#ifndef PRIMITIVECORE_OFFSET_TO_BINARY_I32_H
#define PRIMITIVECORE_OFFSET_TO_BINARY_I32_H

#include <stdbool.h>
#include <stdint.h>

/* Decode binary = code - offset when it fits int32_t.
 * False for a null output or unrepresentable result; failure writes nothing. */
bool rm_offset_to_binary_i32(uint32_t code, uint32_t offset, int32_t *binary);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_offset_to_binary_i32
#define pc_offset_to_binary_i32 rm_offset_to_binary_i32
#endif
#ifndef pc_offset_to_binary_i32
#define pc_offset_to_binary_i32 rm_offset_to_binary_i32
#endif
#ifndef PC_PRIMITIVECORE_OFFSET_TO_BINARY_I32_H
#define PC_PRIMITIVECORE_OFFSET_TO_BINARY_I32_H PRIMITIVECORE_OFFSET_TO_BINARY_I32_H
#endif
