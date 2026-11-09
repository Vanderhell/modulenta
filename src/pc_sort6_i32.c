#include "pc_sort6_i32.h"
#include <stddef.h>

bool pc_sort6_i32(int32_t values[6])
{
    unsigned i, j;
    if (values == NULL) return false;
    for (i = 1; i < 6; ++i) {
        int32_t key = values[i];
        j = i;
        while (j > 0 && values[j - 1] > key) {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = key;
    }
    return true;
}