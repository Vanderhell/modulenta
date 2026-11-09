#ifndef PC_TOKEN_BUCKET_REFILL_U32_H
#define PC_TOKEN_BUCKET_REFILL_U32_H
#include <stdbool.h>
#include <stdint.h>
bool pc_token_bucket_refill_u32(uint32_t tokens, uint32_t elapsed_ticks,
                                uint32_t tokens_per_tick, uint32_t capacity,
                                uint32_t *updated_tokens);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_token_bucket_refill_u32
#define pc_token_bucket_refill_u32 pc_token_bucket_refill_u32
#endif
#ifndef pc_token_bucket_refill_u32
#define pc_token_bucket_refill_u32 pc_token_bucket_refill_u32
#endif
#ifndef PC_TOKEN_BUCKET_REFILL_U32_H
#define PC_TOKEN_BUCKET_REFILL_U32_H PC_TOKEN_BUCKET_REFILL_U32_H
#endif
