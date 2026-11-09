#include "pc_cell_laplacian8_i32.h"
int64_t pc_cell_laplacian8_i32(int32_t c,int32_t n,int32_t ne,int32_t e,int32_t se,int32_t s,int32_t sw,int32_t w,int32_t nw){return ((int64_t)n-c)+((int64_t)ne-c)+((int64_t)e-c)+((int64_t)se-c)+((int64_t)s-c)+((int64_t)sw-c)+((int64_t)w-c)+((int64_t)nw-c);}
