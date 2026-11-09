#include "../include/pc_poly_i32_bound_eval.h"
#include <assert.h>
#include <stdint.h>

int main(void) {
    int64_t lo = 111, hi = 222;
    const int32_t square[] = {1, 0, 0};
    const int32_t linear[] = {-2, 3};
    const int32_t constant[] = {-7};
    const int32_t large[] = {INT32_MAX, INT32_MAX, INT32_MAX};
    assert(pc_poly_i32_bound_eval(square, 3, -1, 1, &lo, &hi));
    assert(lo == -1 && hi == 1); /* conservative enclosure contains [0,1] */
    assert(pc_poly_i32_bound_eval(linear, 2, -5, 4, &lo, &hi));
    assert(lo == -5 && hi == 13);
    assert(pc_poly_i32_bound_eval(constant, 1, INT32_MIN, INT32_MAX, &lo, &hi));
    assert(lo == -7 && hi == -7);
    lo = 111; hi = 222;
    assert(!pc_poly_i32_bound_eval(square, 3, 1, -1, &lo, &hi));
    assert(lo == 111 && hi == 222);
    assert(!pc_poly_i32_bound_eval(0, 1, 0, 1, &lo, &hi));
    assert(!pc_poly_i32_bound_eval(square, 0, 0, 1, &lo, &hi));
    assert(!pc_poly_i32_bound_eval(square, 3, 0, 1, &lo, &lo));
    lo = 111; hi = 222;
    assert(!pc_poly_i32_bound_eval(large, 3, INT32_MAX, INT32_MAX, &lo, &hi));
    assert(lo == 111 && hi == 222);
    return 0;
}