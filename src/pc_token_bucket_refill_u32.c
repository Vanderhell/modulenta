#include "pc_token_bucket_refill_u32.h"
#include <stddef.h>
bool pc_token_bucket_refill_u32(uint32_t tokens, uint32_t elapsed_ticks,
                                uint32_t tokens_per_tick, uint32_t capacity,
                                uint32_t *updated_tokens)
{
    if (updated_tokens == NULL || tokens > capacity) return false;
    uint32_t room = capacity - tokens;
    if (tokens_per_tick != 0u && elapsed_ticks > room / tokens_per_tick) {
        *updated_tokens = capacity;
    } else {
        *updated_tokens = tokens + elapsed_ticks * tokens_per_tick;
    }
    return true;
}