#ifndef PC_MONOTONIC_SEARCH_I32_H
#define PC_MONOTONIC_SEARCH_I32_H
#include <stdbool.h>
#include <stdint.h>
typedef bool (*pc_monotonic_predicate_i32)(int32_t value, void *context);
/* Find first x in inclusive [lo,hi] for which predicate(x,context) is true.
 * Predicate must be deterministic and monotone false->true. Returns API
 * success; found=false means no match. Invalid args preserve both outputs. */
bool pc_monotonic_search_i32(int32_t lo, int32_t hi,
                             pc_monotonic_predicate_i32 predicate,
                             void *context, bool *found, int32_t *first_true);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_monotonic_search_i32
#define pc_monotonic_search_i32 pc_monotonic_search_i32
#endif
#ifndef pc_monotonic_predicate_i32
#define pc_monotonic_predicate_i32 pc_monotonic_predicate_i32
#endif
#ifndef pc_monotonic_search_i32
#define pc_monotonic_search_i32 pc_monotonic_search_i32
#endif
#ifndef PC_MONOTONIC_SEARCH_I32_H
#define PC_MONOTONIC_SEARCH_I32_H PC_MONOTONIC_SEARCH_I32_H
#endif
