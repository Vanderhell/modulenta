#ifndef PC_TABLE_VALIDATE_SORTED_I32_H
#define PC_TABLE_VALIDATE_SORTED_I32_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Return true if values are nondecreasing; duplicates are allowed.
 * An empty table is sorted and may use a null pointer. */
bool pc_table_validate_sorted_i32(const int32_t *values, size_t count);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_table_validate_sorted_i32
#define pc_table_validate_sorted_i32 pc_table_validate_sorted_i32
#endif
#ifndef pc_table_validate_sorted_i32
#define pc_table_validate_sorted_i32 pc_table_validate_sorted_i32
#endif
#ifndef PC_TABLE_VALIDATE_SORTED_I32_H
#define PC_TABLE_VALIDATE_SORTED_I32_H PC_TABLE_VALIDATE_SORTED_I32_H
#endif
