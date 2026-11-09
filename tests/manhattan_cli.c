#include "pc_classify_manhattan_small_i32.h"

#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    int32_t sample[RM_CLASSIFY_MANHATTAN_SMALL_MAX_DIMENSION];
    int32_t centers[RM_CLASSIFY_MANHATTAN_SMALL_MAX_CLASSES *
                    RM_CLASSIFY_MANHATTAN_SMALL_MAX_DIMENSION];
    uint8_t center_count;
    uint8_t dimension;
    uint8_t class_index;
    unsigned class_value;
    unsigned dimension_value;
    unsigned class_id;
    unsigned feature;
    int scanned;

    for (;;) {
        scanned = scanf("%u %u", &class_value, &dimension_value);
        if (scanned == EOF) return 0;
        if (scanned != 2 || class_value > UINT8_MAX ||
            dimension_value > UINT8_MAX) return 2;
        center_count = (uint8_t)class_value;
        dimension = (uint8_t)dimension_value;
        if (center_count == 0u ||
            center_count > RM_CLASSIFY_MANHATTAN_SMALL_MAX_CLASSES ||
            dimension == 0u ||
            dimension > RM_CLASSIFY_MANHATTAN_SMALL_MAX_DIMENSION) return 3;
        for (feature = 0u; feature < dimension; ++feature) {
            if (scanf("%" SCNd32, &sample[feature]) != 1) return 4;
        }
        for (class_id = 0u; class_id < center_count; ++class_id) {
            for (feature = 0u; feature < dimension; ++feature) {
                size_t index = (size_t)class_id * (size_t)dimension + feature;
                if (scanf("%" SCNd32, &centers[index]) != 1) return 5;
            }
        }
        if (!pc_classify_manhattan_small_i32(sample, centers, center_count,
                                             dimension, &class_index)) return 6;
        (void)printf("%u\n", (unsigned)class_index);
    }
}