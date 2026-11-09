#ifndef PRIMITIVECORE_STATE_ONEHOT_INDEX_U32_H
#define PRIMITIVECORE_STATE_ONEHOT_INDEX_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Return the index of the only set bit; reject zero and multi-bit values. */
bool rm_state_onehot_index_u32(uint32_t onehot_value, uint8_t *bit_index);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_state_onehot_index_u32
#define pc_state_onehot_index_u32 rm_state_onehot_index_u32
#endif
#ifndef pc_state_onehot_index_u32
#define pc_state_onehot_index_u32 rm_state_onehot_index_u32
#endif
#ifndef PC_PRIMITIVECORE_STATE_ONEHOT_INDEX_U32_H
#define PC_PRIMITIVECORE_STATE_ONEHOT_INDEX_U32_H PRIMITIVECORE_STATE_ONEHOT_INDEX_U32_H
#endif
