#include "primitivecore/utility/general/bounded/pc_bswap64_u64.h"

uint64_t pc_bswap64_u64(uint64_t value)
{
    return ((value & UINT64_C(0x00000000000000FF)) << 56) |
           ((value & UINT64_C(0x000000000000FF00)) << 40) |
           ((value & UINT64_C(0x0000000000FF0000)) << 24) |
           ((value & UINT64_C(0x00000000FF000000)) << 8) |
           ((value & UINT64_C(0x000000FF00000000)) >> 8) |
           ((value & UINT64_C(0x0000FF0000000000)) >> 24) |
           ((value & UINT64_C(0x00FF000000000000)) >> 40) |
           ((value & UINT64_C(0xFF00000000000000)) >> 56);
}
