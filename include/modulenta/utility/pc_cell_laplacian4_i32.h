#ifndef PC_CELL_LAPLACIAN4_I32_H
#define PC_CELL_LAPLACIAN4_I32_H
#include <stdint.h>
/* Exact four-neighbor discrete Laplacian: north+east+south+west-4*center.
 * Returns an int64 result covering the full int32 input domain. */
int64_t pc_cell_laplacian4_i32(int32_t center,int32_t north,int32_t east,
                               int32_t south,int32_t west);
#endif
