#include "pc_classify_nearest3_i32.h"
#include "pc_nearest_sorted_i32.h"

#include <stddef.h>
#include <stdint.h>

int main(void)
{
    int32_t sample;
    int32_t a;
    int32_t b;
    int32_t c;
    uint8_t candidate;
    size_t generic_index;
    uint64_t comparisons = 0u;

    for (sample = -32; sample <= 31; ++sample) {
        for (a = -32; a <= 31; ++a) {
            for (b = -32; b <= 31; ++b) {
                for (c = -32; c <= 31; ++c) {
                    int32_t sorted[3] = {a, b, c};
                    int32_t temporary;
                    if (sorted[0] > sorted[1]) {
                        temporary = sorted[0]; sorted[0] = sorted[1]; sorted[1] = temporary;
                    }
                    if (sorted[1] > sorted[2]) {
                        temporary = sorted[1]; sorted[1] = sorted[2]; sorted[2] = temporary;
                    }
                    if (sorted[0] > sorted[1]) {
                        temporary = sorted[0]; sorted[0] = sorted[1]; sorted[1] = temporary;
                    }
                    if (!pc_classify_nearest3_i32(sample, sorted[0], sorted[1],
                                                  sorted[2], &candidate) ||
                        !pc_nearest_sorted_i32(sorted, 3u, sample,
                                               &generic_index)) return 1;
                    if (candidate != (uint8_t)generic_index) return 2;
                    ++comparisons;
                }
            }
        }
    }
    return comparisons == UINT64_C(16777216) ? 0 : 3;
}