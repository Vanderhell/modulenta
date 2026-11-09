#ifndef PRIMITIVECORE_SORT4_I32_H
#define PRIMITIVECORE_SORT4_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Sort four caller-owned int32 values into nondecreasing order. */
bool pc_sort4_i32(int32_t values[4]);
#endif
