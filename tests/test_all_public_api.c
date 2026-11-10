#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "pc_accumulate_product_i32.h"
#include "pc_accumulate_square_i32.h"
#include "pc_adc_oversample_accumulate_u32.h"
#include "pc_approx_uniform_knots_u32.h"
#include "pc_arithmetic_sequence_sum_i32.h"
#include "pc_binary_centroid_accum_i32.h"
#include "pc_binary_majority3x3_u32.h"
#include "pc_binary_run_horizontal_u32.h"
#include "pc_binary_to_offset_i32.h"
#include "pc_binary_width_u32.h"
#include "pc_bswap64_u64.h"
#include "pc_calibrate_piecewise_i32.h"
#include "pc_cell_laplacian4_i32.h"
#include "pc_cell_laplacian8_i32.h"
#include "pc_counter_hysteretic_u32.h"
#include "pc_decimal_digit_count_u64.h"
#include "pc_lcg_jump_u32.h"
#include "pc_lower_bound_i32.h"
#include "pc_majority_decode3_u32.h"
#include "pc_midpoint_u64_safe.h"
#include "pc_monotonic_search_i32.h"
#include "pc_nearest_sorted_i32.h"
#include "pc_ntc_adc_from_resistance_u32.h"
#include "pc_offset_to_binary_i32.h"
#include "pc_opt_argmax_small_i32.h"
#include "pc_opt_argmin_small_i32.h"
#include "pc_round_robin_next_u32.h"
#include "pc_sensor_disagreement_i32.h"
#include "pc_signed_width_i32.h"
#include "pc_sort3_i32.h"
#include "pc_sort4_i32.h"
#include "pc_sort5_i32.h"
#include "pc_sort6_i32.h"
#include "pc_sort8_i32.h"
#include "pc_span_overlap_u32.h"
#include "pc_splitmix32_step.h"
#include "pc_state_onehot_check_u32.h"
#include "pc_state_onehot_encode_u32.h"
#include "pc_state_onehot_index_u32.h"
#include "pc_stride_offset_u32.h"
#include "pc_table_nearest_index_i32.h"
#include "pc_table_validate_sorted_i32.h"
#include "pc_token_bucket_consume_u32.h"
#include "pc_token_bucket_refill_u32.h"

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
    return 1; \
} } while (0)

static bool predicate_at_or_above(int32_t value, void *context)
{
    return value >= *(const int32_t *)context;
}

int main(void)
{
    int64_t signed_acc = INT64_MAX;
    uint64_t unsigned_acc = UINT64_MAX;
    uint64_t sum_u64 = 0u;
    int64_t series = 0;
    uint32_t out_u32 = UINT32_C(0xA5A5A5A5), other_u32;
    int32_t out_i32 = 123;
    size_t out_size = 99u;
    uint8_t out_u8 = 99u;
    uint32_t knots[5] = {0u, 0u, 0u, 0u, 0u};
    uint8_t row[] = {0u, 1u, 2u, 0u, 1u};
    uint32_t run = 99u;
    pc_binary_centroid_accum_i32_state centroid = {0, 0, 0u};
    pc_calibration_point_i32 points[] = {{0, 0}, {10, 100}};
    pc_counter_hysteretic_state counter = {0u, false};
    int32_t sorted[] = {INT32_MIN, -4, -4, 0, INT32_MAX};
    int32_t data3[] = {INT32_MAX, 0, INT32_MIN};
    int32_t data4[] = {4, 1, 3, 2};
    int32_t data5[] = {5, 4, 3, 2, 1};
    int32_t data6[] = {6, 5, 4, 3, 2, 1};
    int32_t data8[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int32_t unsorted[] = {2, 1, 3};
    int32_t threshold = 37;
    bool found = false;
    pc_splitmix32_step_result mixed;

    /* Accumulators, overflow-atomic failure, and full-width arithmetic. */
    CHECK(pc_accumulate_product_i32(INT32_MIN, INT32_MIN, &signed_acc) == false);
    CHECK(signed_acc == INT64_MAX);
    signed_acc = 0;
    CHECK(pc_accumulate_product_i32(INT32_MIN, INT32_MAX, &signed_acc));
    CHECK(signed_acc == -INT64_C(4611686016279904256));
    CHECK(!pc_accumulate_product_i32(1, 1, NULL));
    CHECK(!pc_accumulate_square_i32(INT32_MIN, &unsigned_acc) && unsigned_acc == UINT64_MAX);
    unsigned_acc = 0u;
    CHECK(pc_accumulate_square_i32(INT32_MIN, &unsigned_acc));
    CHECK(unsigned_acc == UINT64_C(4611686018427387904));
    CHECK(pc_adc_oversample_accumulate_u32(UINT32_MAX, &sum_u64) && sum_u64 == UINT32_MAX);
    CHECK(!pc_adc_oversample_accumulate_u32(1u, NULL));
    CHECK(pc_arithmetic_sequence_sum_i32(-2, 1, 5u, &series) && series == 0);
    CHECK(!pc_arithmetic_sequence_sum_i32(INT32_MAX, 1, 2u, &series) && series == 0);
    CHECK(pc_arithmetic_sequence_sum_i32(7, INT32_MAX, 0u, &series) && series == 0);

    /* Geometry, encoding, image and calibration helpers. */
    CHECK(pc_approx_uniform_knots_u32(9u, 5u, knots));
    CHECK(knots[0] == 0u && knots[1] == 2u && knots[2] == 4u && knots[3] == 6u && knots[4] == 8u);
    CHECK(!pc_approx_uniform_knots_u32(1u, 1u, knots));
    CHECK(pc_binary_centroid_accum_i32(&centroid, INT32_MIN, INT32_MAX));
    CHECK(centroid.sum_x == INT32_MIN && centroid.sum_y == INT32_MAX && centroid.count == 1u);
    CHECK(!pc_binary_centroid_accum_i32(NULL, 0, 0));
    CHECK(pc_binary_majority3x3_u32(UINT32_C(0x1FF), &out_u32) && out_u32 == 1u);
    CHECK(!pc_binary_majority3x3_u32(UINT32_C(0x200), &out_u32));
    CHECK(pc_binary_run_horizontal_u32(row, 5u, 1u, &run) && run == 2u);
    run = 99u;
    CHECK(!pc_binary_run_horizontal_u32(row, 5u, 6u, &run) && run == 99u);
    CHECK(pc_binary_to_offset_i32(INT32_MIN, UINT32_C(0x80000000), &out_u32) && out_u32 == 0u);
    CHECK(!pc_binary_to_offset_i32(INT32_MAX, UINT32_MAX, &out_u32));
    CHECK(pc_offset_to_binary_i32(0u, UINT32_C(0x80000000), &out_i32) && out_i32 == INT32_MIN);
    CHECK(!pc_offset_to_binary_i32(UINT32_MAX, 0u, &out_i32));
    CHECK(pc_binary_width_u32(0u) == 0u && pc_binary_width_u32(UINT32_MAX) == 32u);
    CHECK(pc_bswap64_u64(UINT64_C(0x0123456789ABCDEF)) == UINT64_C(0xEFCDAB8967452301));
    CHECK(pc_calibrate_piecewise_i32(points, 2u, 5, &out_i32) && out_i32 == 50);
    CHECK(pc_calibrate_piecewise_i32(points, 2u, INT32_MAX, &out_i32) && out_i32 == 100);
    CHECK(!pc_calibrate_piecewise_i32(points, 1u, 5, &out_i32));
    CHECK(pc_cell_laplacian4_i32(0, 1, 2, 3, 4) == 10);
    CHECK(pc_cell_laplacian4_i32(INT32_MIN, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX) == INT64_C(17179869180));
    CHECK(pc_cell_laplacian8_i32(0, 1, 2, 3, 4, 5, 6, 7, 8) == 36);
    CHECK(pc_cell_laplacian8_i32(INT32_MIN, INT32_MAX, INT32_MAX, INT32_MAX,
                                  INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX,
                                  INT32_MAX) == INT64_C(34359738360));
    CHECK(pc_counter_hysteretic_u32(true, 2u, 3u, &counter) && counter.count == 1u && !counter.active);
    CHECK(pc_counter_hysteretic_u32(true, 2u, 3u, &counter) && counter.count == 2u && !counter.active);
    CHECK(pc_counter_hysteretic_u32(true, 2u, 3u, &counter) && counter.count == 3u && counter.active);
    CHECK(pc_counter_hysteretic_u32(false, 2u, 3u, &counter) && counter.count == 2u && !counter.active);
    CHECK(pc_decimal_digit_count_u64(0u) == 1u);
    CHECK(pc_decimal_digit_count_u64(UINT64_MAX) == 20u);

    /* Deterministic state helpers and integer search. */
    CHECK(pc_lcg_jump_u32(1u, 1664525u, 1013904223u, 0u) == 1u);
    other_u32 = 1u;
    other_u32 = other_u32 * 1664525u + 1013904223u;
    CHECK(pc_lcg_jump_u32(1u, 1664525u, 1013904223u, 1u) == other_u32);
    CHECK(pc_lower_bound_i32(sorted, 5u, -4, &out_size) && out_size == 1u);
    CHECK(pc_lower_bound_i32(NULL, 0u, 4, &out_size) && out_size == 0u);
    CHECK(!pc_lower_bound_i32(NULL, 1u, 4, &out_size) && out_size == 0u);
    CHECK(pc_majority_decode3_u32(UINT32_C(0xAAAAAAAA), UINT32_C(0xAAAAAAAA), UINT32_C(0x55555555)) == UINT32_C(0xAAAAAAAA));
    CHECK(pc_midpoint_u64_safe(0u, UINT64_MAX) == UINT64_MAX / 2u);
    CHECK(pc_monotonic_search_i32(INT32_MIN, INT32_MAX, predicate_at_or_above,
                                  &threshold, &found, &out_i32));
    CHECK(found && out_i32 == threshold);
    CHECK(pc_nearest_sorted_i32(sorted, 5u, -3, &out_size) && out_size == 1u);
    CHECK(!pc_nearest_sorted_i32(NULL, 0u, 0, &out_size) && out_size == 1u);
    CHECK(pc_ntc_adc_from_resistance_u32(10000u, 10000u, 4095u, &out_u32) && out_u32 == 2048u);
    CHECK(!pc_ntc_adc_from_resistance_u32(1u, 0u, 4095u, &out_u32));
    CHECK(pc_opt_argmax_small_i32(sorted, 5u, &out_u8) && out_u8 == 4u);
    CHECK(pc_opt_argmin_small_i32(sorted, 5u, &out_u8) && out_u8 == 0u);
    CHECK(pc_round_robin_next_u32(UINT32_MAX, UINT32_MAX, &out_u32) == false);
    CHECK(pc_round_robin_next_u32(2u, 3u, &out_u32) && out_u32 == 0u);
    CHECK(pc_sensor_disagreement_i32(INT32_MIN, INT32_MAX, &out_u32) && out_u32 == UINT32_MAX);
    CHECK(pc_signed_width_i32(0) == 1u);
    CHECK(pc_signed_width_i32(INT32_MIN) == 32u && pc_signed_width_i32(INT32_MAX) == 32u);

    /* Sorts, spans, bit state, indexing, table contracts and token bucket. */
    CHECK(pc_sort3_i32(data3) && data3[0] == INT32_MIN && data3[2] == INT32_MAX);
    CHECK(pc_sort4_i32(data4) && data4[0] == 1 && data4[3] == 4);
    CHECK(pc_sort5_i32(data5) && data5[0] == 1 && data5[4] == 5);
    CHECK(pc_sort6_i32(data6) && data6[0] == 1 && data6[5] == 6);
    CHECK(pc_sort8_i32(data8) && data8[0] == 1 && data8[7] == 8);
    CHECK(pc_span_overlap_u32(10u, 5u, 14u, 3u));
    CHECK(!pc_span_overlap_u32(UINT32_MAX - 1u, 4u, UINT32_MAX - 1u, 4u));
    mixed = pc_splitmix32_step(0u);
    CHECK(mixed.state != 0u && mixed.output != 0u);
    CHECK(!pc_state_onehot_check_u32(0u) && pc_state_onehot_check_u32(UINT32_C(0x80000000)));
    CHECK(pc_state_onehot_encode_u32(31u, &out_u32) && out_u32 == UINT32_C(0x80000000));
    CHECK(!pc_state_onehot_encode_u32(32u, &out_u32));
    CHECK(pc_state_onehot_index_u32(UINT32_C(0x80000000), &out_u8) && out_u8 == 31u);
    CHECK(!pc_state_onehot_index_u32(3u, &out_u8));
    CHECK(pc_stride_offset_u32(3u, 4u, &out_u32) && out_u32 == 12u);
    CHECK(!pc_stride_offset_u32(UINT32_MAX, 2u, &out_u32));
    CHECK(pc_table_nearest_index_i32(sorted, 5u, -3, &out_size) && out_size == 1u);
    CHECK(pc_table_validate_sorted_i32(sorted, 5u));
    CHECK(pc_table_validate_sorted_i32(NULL, 0u));
    CHECK(!pc_table_validate_sorted_i32(unsorted, 3u));
    CHECK(pc_token_bucket_consume_u32(7u, 7u, &out_u32) && out_u32 == 0u);
    out_u32 = 77u;
    CHECK(!pc_token_bucket_consume_u32(2u, 3u, &out_u32) && out_u32 == 77u);
    CHECK(pc_token_bucket_refill_u32(2u, UINT32_MAX, UINT32_MAX, 20u, &out_u32) && out_u32 == 20u);

    puts("all 44 public API entries: boundary checks PASS");
    return 0;
}
