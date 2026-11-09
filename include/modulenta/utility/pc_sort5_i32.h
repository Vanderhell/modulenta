#ifndef PRIMITIVECORE_SORT5_I32_H
#define PRIMITIVECORE_SORT5_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Sort five caller-owned int32 values into nondecreasing order. */
bool pc_sort5_i32(int32_t values[5]);
#endif