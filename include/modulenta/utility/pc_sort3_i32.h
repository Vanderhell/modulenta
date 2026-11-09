#ifndef PRIMITIVECORE_SORT3_I32_H
#define PRIMITIVECORE_SORT3_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Sort three caller-owned int32 values into nondecreasing order. */
bool pc_sort3_i32(int32_t values[3]);
#endif
