#ifndef PC_LCG_JUMP_U32_H
#define PC_LCG_JUMP_U32_H
#include <stdint.h>

/* Advance an LCG state by `steps` transitions of
 * state = multiplier * state + increment modulo 2^32. */
uint32_t pc_lcg_jump_u32(uint32_t state, uint32_t multiplier, uint32_t increment, uint32_t steps);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_lcg_jump_u32
#define pc_lcg_jump_u32 pc_lcg_jump_u32
#endif
#ifndef pc_lcg_jump_u32
#define pc_lcg_jump_u32 pc_lcg_jump_u32
#endif
#ifndef PC_PC_LCG_JUMP_U32_H
#define PC_PC_LCG_JUMP_U32_H PC_LCG_JUMP_U32_H
#endif
