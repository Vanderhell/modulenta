#include "primitivecore/spatial/grid/stencil/pc_cell_laplacian4_i32.h"
int64_t pc_cell_laplacian4_i32(int32_t center,int32_t north,int32_t east,int32_t south,int32_t west){return ((int64_t)north-center)+((int64_t)east-center)+((int64_t)south-center)+((int64_t)west-center);}

