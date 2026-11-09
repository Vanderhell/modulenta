#ifndef PC_SPLITMIX32_STEP_H
#define PC_SPLITMIX32_STEP_H
#include <stdint.h>

typedef struct {
    uint32_t state;
    uint32_t output;
} pc_splitmix32_step_result;

/* Advance a 32-bit Weyl state and return its mixed output. */
pc_splitmix32_step_result pc_splitmix32_step(uint32_t state);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_splitmix32_step
#define pc_splitmix32_step pc_splitmix32_step
#endif
#ifndef pc_splitmix32_step
#define pc_splitmix32_step pc_splitmix32_step
#endif
#ifndef pc_splitmix32_step_result
#define pc_splitmix32_step_result pc_splitmix32_step_result
#endif
#ifndef PC_PC_SPLITMIX32_STEP_H
#define PC_PC_SPLITMIX32_STEP_H PC_SPLITMIX32_STEP_H
#endif
