#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "pc_cluster_assign_nearest_i32.h"
int main(void) {
    unsigned n, i;
    int32_t sample, centers[8];
    uint8_t index;
    while (scanf("%u %" SCNd32, &n, &sample) == 2) {
        if (n == 0u || n > 8u) return 2;
        for (i = 0u; i < n; ++i) {
            if (scanf("%" SCNd32, &centers[i]) != 1) return 3;
        }
        if (!pc_cluster_assign_nearest_i32(centers, (uint8_t)n, sample, &index)) return 4;
        printf("%u\n", (unsigned)index);
    }
    return 0;
}
