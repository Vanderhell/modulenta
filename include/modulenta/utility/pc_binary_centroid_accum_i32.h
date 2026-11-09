#ifndef PC_PC_BINARY_CENTROID_ACCUM_I32_H
#define PC_PC_BINARY_CENTROID_ACCUM_I32_H
#include <stdbool.h>
#include <stdint.h>
typedef struct { int64_t sum_x; int64_t sum_y; uint32_t count; } pc_binary_centroid_accum_i32_state;
/* Zero-initialize; each update adds one foreground pixel coordinate. Sums/count
 * encode the exact rational centroid; false leaves state unchanged. */
bool pc_binary_centroid_accum_i32(pc_binary_centroid_accum_i32_state *state,
                                  int32_t x, int32_t y);
#endif