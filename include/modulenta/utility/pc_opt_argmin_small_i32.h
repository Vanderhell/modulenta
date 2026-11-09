#ifndef PC_OPT_ARGMIN_SMALL_I32_H
#define PC_OPT_ARGMIN_SMALL_I32_H

#include <stdbool.h>
#include <stdint.h>

/* Return the first index of the minimum in 1..8 signed values. `index` must
 * not overlap the input array. Invalid input leaves *index unchanged. */
bool pc_opt_argmin_small_i32(const int32_t *values, uint8_t count,
                             uint8_t *index);

#endif
