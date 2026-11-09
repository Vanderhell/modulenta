#include "primitivecore/utility/ordering/pc_sort3_i32.h"
#include <stddef.h>

static void compare_swap(int32_t *a, int32_t *b)
{
    if (*a > *b) {
        int32_t tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

bool pc_sort3_i32(int32_t values[3])
{
    if (values == NULL) return false;
    compare_swap(&values[0], &values[1]);
    compare_swap(&values[1], &values[2]);
    compare_swap(&values[0], &values[1]);
    return true;
}
