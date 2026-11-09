/* Held-out cross-family validation source; dependency is outside this product. */
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"fail %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    uint32_t out=0;
    CHECK(pc_clock_ppm_compensate_u32(1000001u,1,&out) && out==1000000u);
    CHECK(pc_clock_ppm_compensate_u32(999999u,-1,&out) && out==1000000u);
    CHECK(pc_clock_ppm_compensate_u32(1u,0,&out) && out==1u);
    CHECK(pc_clock_ppm_compensate_u32(1u,1000000,&out) && out==0u);
    CHECK(pc_clock_ppm_compensate_u32(1u,-999872,&out) && out==7812u);
    CHECK(pc_clock_ppm_compensate_u32(3u,-999872,&out) && out==23438u);
    out=77; CHECK(!pc_clock_ppm_compensate_u32(1u,-1000000,&out) && out==77u);
    CHECK(!pc_clock_ppm_compensate_u32(1u,INT32_MIN,&out) && out==77u);
    CHECK(!pc_clock_ppm_compensate_u32(UINT32_MAX,-999999,&out) && out==77u);
    CHECK(!pc_clock_ppm_compensate_u32(1u,0,NULL));
    CHECK(!pc_clock_ppm_compensate_u32(0u,INT32_MIN,&out) && out==77u);
    return 0;
}