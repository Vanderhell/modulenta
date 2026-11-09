#include "../include/pc_poly_i32_sign_at.h"
#include <assert.h>
#include <limits.h>

int main(void) {
    int sign = 77;
    const int32_t square[] = {1, 0, -1};
    const int32_t cubic[] = {1, 0, 0, 0};
    const int32_t cancel[] = {1, -2147483647, -1};
    assert(pc_poly_i32_sign_at(square, 3u, 0, &sign) && sign == -1);
    assert(pc_poly_i32_sign_at(square, 3u, INT32_MIN, &sign) && sign == 1);
    assert(pc_poly_i32_sign_at(cubic, 4u, -2, &sign) && sign == -1);
    assert(pc_poly_i32_sign_at(cancel, 3u, INT32_MAX, &sign) && sign == -1);
    assert(!pc_poly_i32_sign_at(square, 0u, 1, &sign) && sign == -1);
    assert(!pc_poly_i32_sign_at(square, 257u, 1, &sign) && sign == -1);
    assert(!pc_poly_i32_sign_at(0, 1u, 1, &sign) && sign == -1);
    assert(!pc_poly_i32_sign_at(square, 3u, 1, 0));
    return 0;
}