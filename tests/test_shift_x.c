#include "../include/pc_poly_i32_shift_x.h"
#include <assert.h>
#include <limits.h>

int main(void)
{
    int32_t cubic[4] = {1, -2, 3, 4};
    int32_t line[2] = {1, -INT32_MAX};
    int32_t overflow[3] = {1, 0, 0};
    int32_t intermediate_overflow[4] = {1, 0, 0, 0};
    int32_t constant[1] = {INT32_MIN};
    int32_t too_many[17] = {0};
    assert(pc_poly_i32_shift_x(cubic, 4u, 2));
    assert(cubic[0] == 1 && cubic[1] == 4 && cubic[2] == 7 && cubic[3] == 10);
    assert(pc_poly_i32_shift_x(line, 2u, 100));
    assert(line[0] == 1 && line[1] == -2147483547);
    assert((int64_t)line[0]*2147483600 + line[1] == 53);
    assert(!pc_poly_i32_shift_x(overflow, 3u, INT32_MAX));
    assert(overflow[0] == 1 && overflow[1] == 0 && overflow[2] == 0);
    assert(!pc_poly_i32_shift_x(intermediate_overflow, 4u, INT32_MAX));
    assert(intermediate_overflow[0] == 1 && intermediate_overflow[1] == 0 &&
           intermediate_overflow[2] == 0 && intermediate_overflow[3] == 0);
    assert(pc_poly_i32_shift_x(constant, 1u, INT32_MIN));
    assert(constant[0] == INT32_MIN);
    assert(!pc_poly_i32_shift_x(too_many, 17u, 1));
    assert(!pc_poly_i32_shift_x(0, 1u, 1));
    assert(!pc_poly_i32_shift_x(cubic, 0u, 1));
    return 0;
}
