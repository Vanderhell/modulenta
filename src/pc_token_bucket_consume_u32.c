#include <primitivecore/utility/general/bounded/pc_token_bucket_consume_u32.h>
#include <stddef.h>
bool rm_token_bucket_consume_u32(uint32_t tokens, uint32_t requested,
                                 uint32_t *remaining_tokens)
{
    if (remaining_tokens == NULL || requested > tokens) return false;
    *remaining_tokens = tokens - requested;
    return true;
}
