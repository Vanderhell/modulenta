#include <stdint.h>
#include "../include/pc_spi_cs_setup_ticks_u32.c"
int main(void) {
    uint32_t out=55u, seed=0x3068A11u;
    for (uint32_t ns=0; ns<=1000u; ++ns) {
        for (uint32_t hz=1; hz<=1000u; ++hz) {
            uint64_t n=(uint64_t)ns*hz;
            uint64_t expected=n/1000000000u+(n%1000000000u!=0u);
            if (!pc_spi_cs_setup_ticks_u32(ns,hz,&out)||out!=(uint32_t)expected) return 1;
        }
    }
    for (uint32_t i=0;i<1000000u;++i) {
        seed=seed*1664525u+1013904223u; uint32_t ns=seed;
        seed=seed*1664525u+1013904223u; uint32_t hz=seed|1u;
        uint64_t n=(uint64_t)ns*hz;
        uint64_t expected=n/1000000000u+(n%1000000000u!=0u);
        int ok=pc_spi_cs_setup_ticks_u32(ns,hz,&out);
        if (expected>UINT32_MAX) { if(ok) return 2; }
        else if (!ok||out!=(uint32_t)expected) return 3;
    }
    out=77u; if (pc_spi_cs_setup_ticks_u32(1u,0u,&out)||out!=77u) return 4;
    if (pc_spi_cs_setup_ticks_u32(UINT32_MAX,UINT32_MAX,&out)) return 5;
    if (!pc_spi_cs_setup_ticks_u32(1u,UINT32_MAX,&out)||out!=5u) return 6;
    if (pc_spi_cs_setup_ticks_u32(0u,1u,0)) return 7;
    return 0;
}
