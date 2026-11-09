#ifndef PRIMITIVECORE_RM_NEAREST_SORTED_I32_H
#define PRIMITIVECORE_RM_NEAREST_SORTED_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* Return index of nearest value in nondecreasing sorted[]. Equal-distance
 * ties choose the lower value; duplicates choose their first index. False on
 * empty/null input or null output; failure preserves *out_index. */
bool rm_nearest_sorted_i32(const int32_t *sorted, size_t count, int32_t value,
                           size_t *out_index);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_nearest_sorted_i32
#define pc_nearest_sorted_i32 rm_nearest_sorted_i32
#endif
#ifndef pc_nearest_sorted_i32
#define pc_nearest_sorted_i32 rm_nearest_sorted_i32
#endif
#ifndef PC_PRIMITIVECORE_RM_NEAREST_SORTED_I32_H
#define PC_PRIMITIVECORE_RM_NEAREST_SORTED_I32_H PRIMITIVECORE_RM_NEAREST_SORTED_I32_H
#endif

