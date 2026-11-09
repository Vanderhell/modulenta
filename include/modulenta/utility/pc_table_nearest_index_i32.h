#ifndef RM_TABLE_NEAREST_INDEX_I32_H
#define RM_TABLE_NEAREST_INDEX_I32_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Find the closest value in an arbitrary-order table. Equal distances select
 * the lowest table index. Invalid arguments preserve *index. */
bool rm_table_nearest_index_i32(const int32_t *values, size_t count,
                                int32_t query, size_t *index);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_table_nearest_index_i32
#define pc_table_nearest_index_i32 rm_table_nearest_index_i32
#endif
#ifndef pc_table_nearest_index_i32
#define pc_table_nearest_index_i32 rm_table_nearest_index_i32
#endif
#ifndef PC_TABLE_NEAREST_INDEX_I32_H
#define PC_TABLE_NEAREST_INDEX_I32_H RM_TABLE_NEAREST_INDEX_I32_H
#endif
