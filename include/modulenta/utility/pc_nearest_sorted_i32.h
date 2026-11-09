#ifndef PC_PC_NEAREST_SORTED_I32_H
#define PC_PC_NEAREST_SORTED_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* Return index of nearest value in nondecreasing sorted[]. Equal-distance
 * ties choose the lower value; duplicates choose their first index. False on
 * empty/null input or null output; failure preserves *out_index. */
bool pc_nearest_sorted_i32(const int32_t *sorted, size_t count, int32_t value,
                           size_t *out_index);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_nearest_sorted_i32
#define pc_nearest_sorted_i32 pc_nearest_sorted_i32
#endif
#ifndef pc_nearest_sorted_i32
#define pc_nearest_sorted_i32 pc_nearest_sorted_i32
#endif
#ifndef PC_PC_PC_NEAREST_SORTED_I32_H
#define PC_PC_PC_NEAREST_SORTED_I32_H PC_PC_NEAREST_SORTED_I32_H
#endif
