#ifndef PRIMITIVECORE_SPLITMIX32_STEP_H
#define PRIMITIVECORE_SPLITMIX32_STEP_H
#include <stdint.h>

typedef struct {
    uint32_t state;
    uint32_t output;
} rm_splitmix32_step_result;

/* Advance a 32-bit Weyl state and return its mixed output. */
rm_splitmix32_step_result rm_splitmix32_step(uint32_t state);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_splitmix32_step
#define pc_splitmix32_step rm_splitmix32_step
#endif
#ifndef pc_splitmix32_step
#define pc_splitmix32_step rm_splitmix32_step
#endif
#ifndef pc_splitmix32_step_result
#define pc_splitmix32_step_result rm_splitmix32_step_result
#endif
#ifndef PC_PRIMITIVECORE_SPLITMIX32_STEP_H
#define PC_PRIMITIVECORE_SPLITMIX32_STEP_H PRIMITIVECORE_SPLITMIX32_STEP_H
#endif
