#ifndef PRIMITIVECORE_STATE_ONEHOT_ENCODE_U32_H
#define PRIMITIVECORE_STATE_ONEHOT_ENCODE_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Encode a bit index from 0 through 31 as a one-hot uint32 value. */
bool rm_state_onehot_encode_u32(uint8_t bit_index, uint32_t *onehot_value);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_state_onehot_encode_u32
#define pc_state_onehot_encode_u32 rm_state_onehot_encode_u32
#endif
#ifndef pc_state_onehot_encode_u32
#define pc_state_onehot_encode_u32 rm_state_onehot_encode_u32
#endif
#ifndef PC_PRIMITIVECORE_STATE_ONEHOT_ENCODE_U32_H
#define PC_PRIMITIVECORE_STATE_ONEHOT_ENCODE_U32_H PRIMITIVECORE_STATE_ONEHOT_ENCODE_U32_H
#endif

