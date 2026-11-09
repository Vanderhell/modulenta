#ifndef PRIMITIVECORE_APPROX_UNIFOPC_KNOTS_U32_H
#define PRIMITIVECORE_APPROX_UNIFOPC_KNOTS_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Fill knot_count strictly increasing sample indices spanning
 * [0, sample_count - 1], distributed by floor(i*(sample_count-1)/
 * (knot_count-1)). Requires 2 <= knot_count <= sample_count. */
bool pc_approx_uniform_knots_u32(uint32_t sample_count, uint32_t knot_count,
                                 uint32_t *indices);

#endif
