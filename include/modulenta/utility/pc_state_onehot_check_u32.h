#ifndef PRIMITIVECORE_STATE_ONEHOT_CHECK_U32_H
#define PRIMITIVECORE_STATE_ONEHOT_CHECK_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Return true iff exactly one bit is set; zero is not one-hot. */
bool rm_state_onehot_check_u32(uint32_t value);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_state_onehot_check_u32
#define pc_state_onehot_check_u32 rm_state_onehot_check_u32
#endif
#ifndef pc_state_onehot_check_u32
#define pc_state_onehot_check_u32 rm_state_onehot_check_u32
#endif
#ifndef PC_PRIMITIVECORE_STATE_ONEHOT_CHECK_U32_H
#define PC_PRIMITIVECORE_STATE_ONEHOT_CHECK_U32_H PRIMITIVECORE_STATE_ONEHOT_CHECK_U32_H
#endif

