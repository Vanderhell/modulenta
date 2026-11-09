#ifndef PRIMITIVECORE_RM_LOWER_BOUND_I32_H
#define PRIMITIVECORE_RM_LOWER_BOUND_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* First index i with sorted[i] >= value, or count if none. Input must be
 * nondecreasing. Null sorted is valid only for count==0; failure preserves out. */
bool rm_lower_bound_i32(const int32_t *sorted, size_t count, int32_t value,
                        size_t *out_index);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_lower_bound_i32
#define pc_lower_bound_i32 rm_lower_bound_i32
#endif
#ifndef pc_lower_bound_i32
#define pc_lower_bound_i32 rm_lower_bound_i32
#endif
#ifndef PC_PRIMITIVECORE_RM_LOWER_BOUND_I32_H
#define PC_PRIMITIVECORE_RM_LOWER_BOUND_I32_H PRIMITIVECORE_RM_LOWER_BOUND_I32_H
#endif

