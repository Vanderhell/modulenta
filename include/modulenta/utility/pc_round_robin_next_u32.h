#ifndef PRIMITIVECORE_ROUND_ROBIN_NEXT_U32_H
#define PRIMITIVECORE_ROUND_ROBIN_NEXT_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Advance a valid index in [0,count), wrapping to zero; reject invalid state. */
bool rm_round_robin_next_u32(uint32_t current, uint32_t count,
                             uint32_t *next);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_round_robin_next_u32
#define pc_round_robin_next_u32 rm_round_robin_next_u32
#endif
#ifndef pc_round_robin_next_u32
#define pc_round_robin_next_u32 rm_round_robin_next_u32
#endif
#ifndef PC_PRIMITIVECORE_ROUND_ROBIN_NEXT_U32_H
#define PC_PRIMITIVECORE_ROUND_ROBIN_NEXT_U32_H PRIMITIVECORE_ROUND_ROBIN_NEXT_U32_H
#endif

