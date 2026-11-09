#include <primitivecore/arithmetic/integer/bounded/pc_accumulate_product_i32.h>
#include <stddef.h>

bool rm_accumulate_product_i32(int32_t a, int32_t b, int64_t *accumulator)
{
    int64_t product, sum;
    if (accumulator == NULL) return false;
    product = (int64_t)a * (int64_t)b;
    sum = *accumulator;
    if ((product > 0 && sum > INT64_MAX - product) ||
        (product < 0 && sum < INT64_MIN - product)) return false;
    *accumulator = sum + product;
    return true;
}

