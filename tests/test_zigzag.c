/* Held-out cross-family validation source; dependency is outside this product. */
#include <assert.h>
#include <limits.h>
#include <stdint.h>
static uint32_t ref(int32_t x){return x>=0?((uint32_t)x*2u):((uint32_t)(-(int64_t)x)*2u-1u);}
static int32_t inverse(uint32_t z){int64_t x=(z&1u)?-(int64_t)((z>>1)+1u):(int64_t)(z>>1);return (int32_t)x;}
int main(void){int32_t x;uint32_t z;for(x=INT16_MIN;x<=INT16_MAX;++x){z=pc_residual_zigzag_u32(x);assert(z==ref(x));assert(inverse(z)==x);}
 assert(pc_residual_zigzag_u32(0)==0u);assert(pc_residual_zigzag_u32(-1)==1u);assert(pc_residual_zigzag_u32(1)==2u);assert(pc_residual_zigzag_u32(INT32_MAX)==UINT32_MAX-1u);assert(pc_residual_zigzag_u32(INT32_MIN)==UINT32_MAX);return 0;}