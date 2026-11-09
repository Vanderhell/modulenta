#ifndef RM_TOKEN_BUCKET_CONSUME_U32_H
#define RM_TOKEN_BUCKET_CONSUME_U32_H
#include <stdbool.h>
#include <stdint.h>
bool rm_token_bucket_consume_u32(uint32_t tokens, uint32_t requested,
                                 uint32_t *remaining_tokens);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_token_bucket_consume_u32
#define pc_token_bucket_consume_u32 rm_token_bucket_consume_u32
#endif
#ifndef pc_token_bucket_consume_u32
#define pc_token_bucket_consume_u32 rm_token_bucket_consume_u32
#endif
#ifndef PC_TOKEN_BUCKET_CONSUME_U32_H
#define PC_TOKEN_BUCKET_CONSUME_U32_H RM_TOKEN_BUCKET_CONSUME_U32_H
#endif

