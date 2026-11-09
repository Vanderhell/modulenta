#include "pc_classify_nearest2_i32.h"

#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    int32_t sample;
    int32_t center0;
    int32_t center1;
    uint8_t class_index;
    int scanned;

    while ((scanned = scanf("%" SCNd32 " %" SCNd32 " %" SCNd32,
                             &sample, &center0, &center1)) == 3) {
        if (!pc_classify_nearest2_i32(sample, center0, center1, &class_index)) {
            return 1;
        }
        (void)printf("%u\n", (unsigned)class_index);
    }
    return scanned == EOF ? 0 : 2;
}