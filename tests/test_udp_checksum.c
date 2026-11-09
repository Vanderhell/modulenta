#include "pc_udp_checksum_span_u32.h"

#include <stddef.h>
#include <stdint.h>

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    static const uint8_t src4[4] = {192u, 0u, 2u, 1u};
    static const uint8_t dst4[4] = {198u, 51u, 100u, 2u};
    static const uint8_t src6[16] = {
        0x20u, 0x01u, 0x0du, 0xb8u, 0u, 0u, 0u, 0u,
        0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u
    };
    static const uint8_t dst6[16] = {
        0x20u, 0x01u, 0x0du, 0xb8u, 0u, 0u, 0u, 0u,
        0u, 0u, 0u, 0u, 0u, 0u, 0u, 2u
    };
    uint8_t segment[13] = {
        0x12u, 0x34u, 0x56u, 0x78u, 0u, 13u, 0xab, 0xcdu,
        'a', 'b', 'c', 'd', 'e'
    };
    uint8_t empty[8] = {0u, 1u, 0u, 2u, 0u, 8u, 0u, 0u};
    uint8_t zero_result[10] = {
        0x12u, 0x34u, 0x56u, 0x78u, 0u, 10u, 0u, 0u, 0xaau, 0xf6u
    };
    static uint8_t too_big_v4[65516u] = {0u, 1u, 0u, 2u, 0xffu, 0xecu};
    static uint8_t too_big_v6[65536u] = {0u, 1u, 0u, 2u, 0u, 0u};
    uint32_t out = UINT32_C(0xdeadbeef);

    CHECK(pc_udp_checksum_span_u32(4u, src4, dst4, segment, sizeof segment, &out));
    CHECK(out == UINT32_C(0x8129));
    CHECK(segment[6u] == 0xabu && segment[7u] == 0xcdu);
    CHECK(pc_udp_checksum_span_u32(6u, src6, dst6, segment, sizeof segment, &out));
    CHECK(out == UINT32_C(0x11ec));
    CHECK(segment[6u] == 0xabu && segment[7u] == 0xcdu);
    CHECK(pc_udp_checksum_span_u32(4u, src4, dst4, empty, sizeof empty, &out));
    CHECK(out == UINT32_C(0x13a4));
    CHECK(pc_udp_checksum_span_u32(4u, src4, dst4, zero_result,
                                   sizeof zero_result, &out));
    CHECK(out == UINT32_C(0xffff));

    out = UINT32_C(0xdeadbeef);
    CHECK(!pc_udp_checksum_span_u32(5u, src4, dst4, segment, sizeof segment, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    CHECK(!pc_udp_checksum_span_u32(4u, src4, dst4, segment, 12u, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    CHECK(!pc_udp_checksum_span_u32(4u, src4, dst4, segment, 7u, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    CHECK(!pc_udp_checksum_span_u32(4u, src4, dst4, too_big_v4,
                                    sizeof too_big_v4, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    CHECK(!pc_udp_checksum_span_u32(6u, src6, dst6, too_big_v6,
                                    sizeof too_big_v6, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    CHECK(!pc_udp_checksum_span_u32(4u, NULL, dst4, segment, sizeof segment, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    CHECK(!pc_udp_checksum_span_u32(4u, src4, dst4, segment, sizeof segment, NULL));

    segment[5] = 12u;
    CHECK(!pc_udp_checksum_span_u32(4u, src4, dst4, segment, sizeof segment, &out));
    CHECK(out == UINT32_C(0xdeadbeef));
    return 0;
}
