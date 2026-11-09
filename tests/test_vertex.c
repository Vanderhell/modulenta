#include "../include/pc_poly_i32_vertex_hint.h"
#include <assert.h>
#include <limits.h>

int main(void)
{
    pc_poly_i32_vertex v = {99, 77u, false};
    const int32_t q1[] = {2, -4, 99};
    const int32_t q2[] = {-1, INT32_MIN, 0};
    const int32_t q3[] = {INT32_MIN, INT32_MIN, INT32_MAX};
    const int32_t linear[] = {0, 1, 2};
    assert(pc_poly_i32_vertex_hint(q1, &v));
    assert(v.numerator == 1 && v.denominator == 1u && v.is_minimum);
    assert(pc_poly_i32_vertex_hint(q2, &v));
    assert(v.numerator == -1073741824 && v.denominator == 1u && !v.is_minimum);
    assert(pc_poly_i32_vertex_hint(q3, &v));
    assert(v.numerator == -1 && v.denominator == 2u && !v.is_minimum);
    v.numerator = 99; v.denominator = 77u; v.is_minimum = true;
    assert(!pc_poly_i32_vertex_hint(linear, &v));
    assert(v.numerator == 99 && v.denominator == 77u && v.is_minimum);
    assert(!pc_poly_i32_vertex_hint(q1, 0));
    assert(!pc_poly_i32_vertex_hint(0, &v));
    return 0;
}