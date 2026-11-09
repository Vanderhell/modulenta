#include "pc_sensor_disagreement_i32.h"
bool rm_sensor_disagreement_i32(int32_t sensor0, int32_t sensor1, uint32_t *distance)
{
    if (distance == 0) return false;
    if (sensor0 >= sensor1) *distance = (uint32_t)sensor0 - (uint32_t)sensor1;
    else *distance = (uint32_t)sensor1 - (uint32_t)sensor0;
    return true;
}