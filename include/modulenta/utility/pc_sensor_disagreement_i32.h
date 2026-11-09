#ifndef RM_SENSOR_DISAGREEMENT_I32_H
#define RM_SENSOR_DISAGREEMENT_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Exact absolute difference; UINT32_MAX is representable for opposite extremes. */
bool rm_sensor_disagreement_i32(int32_t sensor0, int32_t sensor1, uint32_t *distance);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_sensor_disagreement_i32
#define pc_sensor_disagreement_i32 rm_sensor_disagreement_i32
#endif
#ifndef pc_sensor_disagreement_i32
#define pc_sensor_disagreement_i32 rm_sensor_disagreement_i32
#endif
#ifndef PC_SENSOR_DISAGREEMENT_I32_H
#define PC_SENSOR_DISAGREEMENT_I32_H RM_SENSOR_DISAGREEMENT_I32_H
#endif

