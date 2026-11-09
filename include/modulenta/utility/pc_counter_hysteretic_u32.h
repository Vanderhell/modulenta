#ifndef PRIMITIVECORE_COUNTER_HYSTERETIC_U32_H
#define PRIMITIVECORE_COUNTER_HYSTERETIC_U32_H
#include <stdbool.h>
#include <stdint.h>
typedef struct { uint32_t count; bool active; } rm_counter_hysteretic_state;
/* Integrate true samples up and false samples down; switch at separate thresholds. */
bool rm_counter_hysteretic_u32(bool sample, uint32_t lower, uint32_t upper,
                               rm_counter_hysteretic_state *state);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_counter_hysteretic_u32
#define pc_counter_hysteretic_u32 rm_counter_hysteretic_u32
#endif
#ifndef pc_counter_hysteretic_state
#define pc_counter_hysteretic_state rm_counter_hysteretic_state
#endif
#ifndef pc_counter_hysteretic_u32
#define pc_counter_hysteretic_u32 rm_counter_hysteretic_u32
#endif
#ifndef PC_PRIMITIVECORE_COUNTER_HYSTERETIC_U32_H
#define PC_PRIMITIVECORE_COUNTER_HYSTERETIC_U32_H PRIMITIVECORE_COUNTER_HYSTERETIC_U32_H
#endif

