#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

bool pc_onewire_rom_validate_u32(uint32_t rom_low, uint32_t rom_high);

static uint8_t reflect8(uint8_t value)
{
    unsigned i;
    uint8_t result = 0u;
    for (i = 0u; i < 8u; ++i) {
        result = (uint8_t)((result << 1u) | (value & 1u));
        value >>= 1u;
    }
    return result;
}

static uint8_t oracle_step(uint8_t crc, uint8_t byte)
{
    uint8_t reg = (uint8_t)(reflect8(crc) ^ reflect8(byte));
    unsigned i;
    for (i = 0u; i < 8u; ++i) {
        uint32_t shifted = (uint32_t)reg << 1u;
        if ((reg & UINT8_C(0x80)) != 0u) shifted ^= UINT32_C(0x31);
        reg = (uint8_t)shifted;
    }
    return reflect8(reg);
}

static bool oracle(uint32_t lo, uint32_t hi)
{
    uint8_t crc = 0u;
    unsigned i;
    for (i = 0u; i < 4u; ++i) crc = oracle_step(crc, (uint8_t)(lo >> (8u*i)));
    for (i = 0u; i < 3u; ++i) crc = oracle_step(crc, (uint8_t)(hi >> (8u*i)));
    return crc == (uint8_t)(hi >> 24u);
}

int main(void)
{
    uint32_t seed = UINT32_C(0x3112c0de);
    unsigned i;
    /* Exhaust all 16-bit prefixes while varying serial/family upper bits. */
    for (i = 0u; i < 65536u; ++i) {
        uint32_t lo = (uint32_t)i | UINT32_C(0x28000000);
        uint32_t hi = UINT32_C(0x12345678);
        assert(pc_onewire_rom_validate_u32(lo, hi) == oracle(lo, hi));
    }
    /* Deterministic full-width differential. */
    for (i = 0u; i < 1000000u; ++i) {
        uint32_t lo, hi;
        seed = seed * UINT32_C(1664525) + UINT32_C(1013904223); lo = seed;
        seed = seed * UINT32_C(1664525) + UINT32_C(1013904223); hi = seed;
        assert(pc_onewire_rom_validate_u32(lo, hi) == oracle(lo, hi));
    }
    /* Every byte sequence constructed with its actual CRC is accepted. */
    for (i = 0u; i < 256u; ++i) {
        uint32_t lo = i | UINT32_C(0x01020300);
        uint32_t hi = UINT32_C(0xA1B2C300);
        uint8_t crc = 0u;
        unsigned j;
        for (j = 0u; j < 4u; ++j) crc = oracle_step(crc, (uint8_t)(lo >> (8u*j)));
        for (j = 0u; j < 3u; ++j) crc = oracle_step(crc, (uint8_t)(hi >> (8u*j)));
        hi = (hi & UINT32_C(0x00FFFFFF)) | ((uint32_t)crc << 24u);
        assert(pc_onewire_rom_validate_u32(lo, hi));
        assert(!pc_onewire_rom_validate_u32(lo, hi ^ UINT32_C(0x01000000)));
    }
    return 0;
}