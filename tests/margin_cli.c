#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "pc_classify_argmax_margin_i32.h"
int main(void) {
    unsigned count, i; int32_t values[8]; uint8_t winner; uint32_t margin;
    while (scanf("%u", &count) == 1) {
        if (count < 2u || count > 8u) return 2;
        for (i=0u;i<count;++i) if (scanf("%" SCNd32, &values[i]) != 1) return 3;
        if (!pc_classify_argmax_margin_i32(values,(uint8_t)count,&winner,&margin)) return 4;
        printf("%u %" PRIu32 "\n",(unsigned)winner,margin);
    }
    return 0;
}
