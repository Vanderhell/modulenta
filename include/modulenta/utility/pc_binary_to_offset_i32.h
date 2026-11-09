#ifndef PRIMITIVECORE_BINARY_TO_OFFSET_I32_H
#define PRIMITIVECORE_BINARY_TO_OFFSET_I32_H

#include <stdbool.h>
#include <stdint.h>

/* Encode signed binary as code = binary + offset in uint32 range.
 * False for a null output or unrepresentable code; failure writes nothing. */
bool rm_binary_to_offset_i32(int32_t binary, uint32_t offset, uint32_t *code);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_binary_to_offset_i32
#define pc_binary_to_offset_i32 rm_binary_to_offset_i32
#endif
#ifndef pc_binary_to_offset_i32
#define pc_binary_to_offset_i32 rm_binary_to_offset_i32
#endif
#ifndef PC_PRIMITIVECORE_BINARY_TO_OFFSET_I32_H
#define PC_PRIMITIVECORE_BINARY_TO_OFFSET_I32_H PRIMITIVECORE_BINARY_TO_OFFSET_I32_H
#endif
