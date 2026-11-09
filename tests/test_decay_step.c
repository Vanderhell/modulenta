#include "pc_decay_step_i32.h"
#include <assert.h>
#include <stdint.h>

int main(void)
{
    unsigned i;
    int32_t value = INT32_MIN;
    assert(pc_decay_step_i32(INT32_MIN, 0u) == INT32_MIN);
    assert(pc_decay_step_i32(INT32_MIN, UINT32_MAX) == 0);
    assert(pc_decay_step_i32(-12, 5u) == -7);
    assert(pc_decay_step_i32(-12, 12u) == 0);
    assert(pc_decay_step_i32(12, 13u) == 0);
    assert(pc_decay_step_i32(INT32_MAX, 1u) == INT32_MAX - 1);
    for (i = 0u; i < 100000u; ++i) {
        value = pc_decay_step_i32(value, 12345u);
    }
    assert(value == -912983648);
    return 0;
}