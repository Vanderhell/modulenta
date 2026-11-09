#ifndef RM_STRIDE_OFFSET_U32_H
#define RM_STRIDE_OFFSET_U32_H
#include <stdbool.h>
#include <stdint.h>
bool rm_stride_offset_u32(uint32_t index, uint32_t stride, uint32_t *offset);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_stride_offset_u32
#define pc_stride_offset_u32 rm_stride_offset_u32
#endif
#ifndef pc_stride_offset_u32
#define pc_stride_offset_u32 rm_stride_offset_u32
#endif
#ifndef PC_STRIDE_OFFSET_U32_H
#define PC_STRIDE_OFFSET_U32_H RM_STRIDE_OFFSET_U32_H
#endif

