#ifndef PC_CELL_LAPLACIAN8_I32_H
#define PC_CELL_LAPLACIAN8_I32_H
#include <stdint.h>
/* Exact unweighted Moore-neighborhood Laplacian: sum(eight neighbors)-8*center. */
int64_t pc_cell_laplacian8_i32(int32_t center,int32_t n,int32_t ne,int32_t e,
 int32_t se,int32_t s,int32_t sw,int32_t w,int32_t nw);
#endif
