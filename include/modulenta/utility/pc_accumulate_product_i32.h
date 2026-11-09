#ifndef RM_ACCUMULATE_PRODUCT_I32_H
#define RM_ACCUMULATE_PRODUCT_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Add a*b exactly to *accumulator; signed overflow leaves it unchanged. */
bool rm_accumulate_product_i32(int32_t a, int32_t b, int64_t *accumulator);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_accumulate_product_i32
#define pc_accumulate_product_i32 rm_accumulate_product_i32
#endif
#ifndef pc_accumulate_product_i32
#define pc_accumulate_product_i32 rm_accumulate_product_i32
#endif
#ifndef PC_ACCUMULATE_PRODUCT_I32_H
#define PC_ACCUMULATE_PRODUCT_I32_H RM_ACCUMULATE_PRODUCT_I32_H
#endif

