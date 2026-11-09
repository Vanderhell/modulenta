#include "../include/pc_poly_i32_symmetry_hint.h"
#include <assert.h>

int main(void)
{
    pc_poly_i32_symmetry result = PC_POLY_I32_SYM_BOTH;
    const int32_t even[] = {1,0,2};
    const int32_t odd[] = {1,0,2,0};
    const int32_t neither[] = {1,1};
    const int32_t zero[] = {0,0,0};
    assert(pc_poly_i32_symmetry_hint(even,3u,&result) && result==PC_POLY_I32_SYM_EVEN);
    assert(pc_poly_i32_symmetry_hint(odd,4u,&result) && result==PC_POLY_I32_SYM_ODD);
    assert(pc_poly_i32_symmetry_hint(neither,2u,&result) && result==PC_POLY_I32_SYM_NEITHER);
    assert(pc_poly_i32_symmetry_hint(zero,3u,&result) && result==PC_POLY_I32_SYM_BOTH);
    result=PC_POLY_I32_SYM_ODD;
    assert(!pc_poly_i32_symmetry_hint(even,0u,&result) && result==PC_POLY_I32_SYM_ODD);
    assert(!pc_poly_i32_symmetry_hint(0,1u,&result) && result==PC_POLY_I32_SYM_ODD);
    assert(!pc_poly_i32_symmetry_hint(even,3u,0));
    return 0;
}