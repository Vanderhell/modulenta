#include "pc_udp_payload_max_u32.h"
#include <stdint.h>

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

static int reference(uint32_t mtu, uint32_t version, uint32_t header,
                     uint32_t *result)
{
    uint64_t packet_limit;
    uint64_t budget;
    uint64_t payload;
    if (version == 4u) {
        if (header < 20u || header > 60u || (header & 3u) != 0u) return 0;
        packet_limit = UINT64_C(65535);
    } else if (version == 6u) {
        if (header < 40u) return 0;
        packet_limit = UINT64_C(65575);
    } else {
        return 0;
    }
    budget = mtu < packet_limit ? mtu : packet_limit;
    if (budget < (uint64_t)header + UINT64_C(8)) return 0;
    payload = budget - header - UINT64_C(8);
    if (payload > UINT64_C(65527)) payload = UINT64_C(65527);
    *result = (uint32_t)payload;
    return 1;
}

int main(void)
{
    uint32_t expected;
    uint32_t actual;

    CHECK(pc_udp_payload_max_u32(1500u, 4u, 20u, &actual) && actual == 1472u);
    CHECK(pc_udp_payload_max_u32(1500u, 4u, 60u, &actual) && actual == 1432u);
    CHECK(pc_udp_payload_max_u32(1500u, 6u, 40u, &actual) && actual == 1452u);
    CHECK(pc_udp_payload_max_u32(100000u, 4u, 20u, &actual) && actual == 65507u);
    CHECK(pc_udp_payload_max_u32(100000u, 6u, 40u, &actual) && actual == 65527u);
    CHECK(pc_udp_payload_max_u32(28u, 4u, 20u, &actual) && actual == 0u);

    actual = UINT32_C(0xA5A5A5A5);
    CHECK(!pc_udp_payload_max_u32(27u, 4u, 20u, &actual));
    CHECK(actual == UINT32_C(0xA5A5A5A5));
    CHECK(!pc_udp_payload_max_u32(1500u, 4u, 21u, &actual));
    CHECK(!pc_udp_payload_max_u32(1500u, 4u, 64u, &actual));
    CHECK(!pc_udp_payload_max_u32(1500u, 6u, 39u, &actual));
    CHECK(!pc_udp_payload_max_u32(1500u, 5u, 20u, &actual));
    CHECK(!pc_udp_payload_max_u32(UINT32_MAX, 6u, UINT32_MAX, &actual));
    CHECK(!pc_udp_payload_max_u32(1500u, 4u, 20u, 0));

    for (uint32_t header = 20u; header <= 60u; header += 4u) {
        for (uint32_t mtu = 0u; mtu <= 65575u; ++mtu) {
            int valid = reference(mtu, 4u, header, &expected);
            actual = UINT32_C(0xA5A5A5A5);
            CHECK(pc_udp_payload_max_u32(mtu, 4u, header, &actual) == (valid != 0));
            if (valid) CHECK(actual == expected);
            else CHECK(actual == UINT32_C(0xA5A5A5A5));
        }
    }
    for (uint32_t header = 40u; header <= 128u; ++header) {
        for (uint32_t mtu = 0u; mtu <= 65575u; ++mtu) {
            int valid = reference(mtu, 6u, header, &expected);
            actual = UINT32_C(0xA5A5A5A5);
            CHECK(pc_udp_payload_max_u32(mtu, 6u, header, &actual) == (valid != 0));
            if (valid) CHECK(actual == expected);
            else CHECK(actual == UINT32_C(0xA5A5A5A5));
        }
    }

    {
        uint32_t state = UINT32_C(0x4121C0DE);
        for (uint32_t i = 0u; i < UINT32_C(1000000); ++i) {
            uint32_t version;
            uint32_t header;
            uint32_t mtu;
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            version = (state & 1u) != 0u ? 4u : 6u;
            if (version == 4u) {
                state = state * UINT32_C(1664525) + UINT32_C(1013904223);
                header = 20u + 4u * (state % 11u);
            } else {
                state = state * UINT32_C(1664525) + UINT32_C(1013904223);
                header = 40u + (state % 472u);
            }
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            mtu = header + 8u + state % (UINT32_MAX - header - 7u);
            CHECK(reference(mtu, version, header, &expected));
            CHECK(pc_udp_payload_max_u32(mtu, version, header, &actual));
            CHECK(actual == expected);
        }
    }
    return 0;
}
