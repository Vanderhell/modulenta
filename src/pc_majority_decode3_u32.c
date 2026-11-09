#include "pc_majority_decode3_u32.h"

uint32_t pc_majority_decode3_u32(uint32_t a, uint32_t b, uint32_t c)
{
    return (a & b) | (a & c) | (b & c);
}