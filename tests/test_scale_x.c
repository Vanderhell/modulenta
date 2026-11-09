#include "../include/pc_poly_i32_scale_x.h"
#include <assert.h>
#include <limits.h>

int main(void)
{
    int32_t c[4] = {1, -2, 3, 4};
    int32_t zero_scale[3] = {INT32_MAX, INT32_MIN, 7};
    int32_t overflow[3] = {INT32_MAX, 0, 5};
    int32_t negative_scale[2] = {1, 2};
    int32_t overflow_after_zero[3] = {-1, 0, INT32_MAX};
    int32_t max_count[256] = {0};
    int32_t original[3] = {1, 2, 3};
    int32_t invalid[3] = {1, 2, 3};
    assert(pc_poly_i32_scale_x(c, 4u, 2));
    assert(c[0] == 8 && c[1] == -8 && c[2] == 6 && c[3] == 4);
    assert(pc_poly_i32_scale_x(zero_scale, 3u, 0));
    assert(zero_scale[0] == 0 && zero_scale[1] == 0 && zero_scale[2] == 7);
    assert(pc_poly_i32_scale_x(negative_scale, 2u, -1));
    assert(negative_scale[0] == -1 && negative_scale[1] == 2);
    assert(!pc_poly_i32_scale_x(overflow, 3u, 2));
    assert(overflow[0] == INT32_MAX && overflow[1] == 0 && overflow[2] == 5);
    assert(!pc_poly_i32_scale_x(overflow_after_zero, 3u, INT32_MIN));
    assert(overflow_after_zero[0] == -1 && overflow_after_zero[1] == 0 &&
           overflow_after_zero[2] == INT32_MAX);
    assert(pc_poly_i32_scale_x(original, 3u, 1));
    assert(original[0] == 1 && original[1] == 2 && original[2] == 3);
    max_count[255] = 7;
    assert(pc_poly_i32_scale_x(max_count, 256u, INT32_MAX));
    assert(max_count[255] == 7);
    assert(!pc_poly_i32_scale_x(invalid, 0u, 1));
    assert(invalid[0] == 1 && invalid[1] == 2 && invalid[2] == 3);
    assert(!pc_poly_i32_scale_x(0, 3u, 1));
    assert(!pc_poly_i32_scale_x(invalid, 257u, 1));
    return 0;
}
