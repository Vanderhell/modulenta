#include <primitivecore/utility/general/bounded/pc_table_validate_sorted_i32.h>

bool rm_table_validate_sorted_i32(const int32_t *values, size_t count)
{
    size_t i;
    if (values == NULL) return count == 0u;
    for (i = 1u; i < count; ++i) {
        if (values[i - 1u] > values[i]) return false;
    }
    return true;
}
