# Modulenta API reference

Complete public-header inventory generated from the current source tree. Headers remain authoritative.

## include/modulenta/utility/pc_accumulate_product_i32.h

Public API: pc_accumulate_product_i32

Contract: Add a*b exactly to *accumulator; signed overflow leaves it unchanged.

Header path: include/modulenta/utility/pc_accumulate_product_i32.h

## include/modulenta/utility/pc_accumulate_square_i32.h

Public API: pc_accumulate_square_i32

Contract: Add value squared to *accumulator; overflow leaves it unchanged.

Header path: include/modulenta/utility/pc_accumulate_square_i32.h

## include/modulenta/utility/pc_adc_oversample_accumulate_u32.h

Public API: pc_adc_oversample_accumulate_u32

Contract: Add one ADC code to a caller-owned uint64 sum. Overflow/null fails atomically.

Header path: include/modulenta/utility/pc_adc_oversample_accumulate_u32.h

## include/modulenta/utility/pc_approx_uniform_knots_u32.h

Public API: pc_approx_uniform_knots_u32

Contract: Fill knot_count strictly increasing sample indices spanning [0, sample_count - 1], distributed by floor(i*(sample_count-1)/ (knot_count-1)). Requires 2 <= knot_count <= sample_count.

Header path: include/modulenta/utility/pc_approx_uniform_knots_u32.h

## include/modulenta/utility/pc_arithmetic_sequence_sum_i32.h

Public API: pc_arithmetic_sequence_sum_i32

Contract: Sum count terms start + i*step, i=0..count-1. Every term must fit int32. Returns exact int64 sum; count zero returns zero. False leaves sum unchanged.

Header path: include/modulenta/utility/pc_arithmetic_sequence_sum_i32.h

## include/modulenta/utility/pc_binary_centroid_accum_i32.h

Public API: pc_binary_centroid_accum_i32

Contract: Zero-initialize; each update adds one foreground pixel coordinate. Sums/count encode the exact rational centroid; false leaves state unchanged.

Header path: include/modulenta/utility/pc_binary_centroid_accum_i32.h

## include/modulenta/utility/pc_binary_majority3x3_u32.h

Public API: pc_binary_majority3x3_u32

Contract: Low 9 bits encode a complete 3x3 neighborhood, row-major; output is 0/1. False for high bits or null result; failure preserves *result.

Header path: include/modulenta/utility/pc_binary_majority3x3_u32.h

## include/modulenta/utility/pc_binary_run_horizontal_u32.h

Public API: pc_binary_run_horizontal_u32

Contract: Count consecutive nonzero row samples from start_x to the first zero or width. start_x==width returns zero. Invalid arguments preserve *run_length.

Header path: include/modulenta/utility/pc_binary_run_horizontal_u32.h

## include/modulenta/utility/pc_binary_to_offset_i32.h

Public API: pc_binary_to_offset_i32

Contract: Encode signed binary as code = binary + offset in uint32 range. False for a null output or unrepresentable code; failure writes nothing.

Header path: include/modulenta/utility/pc_binary_to_offset_i32.h

## include/modulenta/utility/pc_binary_width_u32.h

Public API: pc_binary_width_u32

Contract: Return the number of significant binary digits; zero has width zero.

Header path: include/modulenta/utility/pc_binary_width_u32.h

## include/modulenta/utility/pc_bswap64_u64.h

Public API: pc_bswap64_u64

Contract: Reverse the eight byte positions in a uint64 value.

Header path: include/modulenta/utility/pc_bswap64_u64.h

## include/modulenta/utility/pc_calibrate_piecewise_i32.h

Public API: pc_calibrate_piecewise_i32

Contract: Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing.

Header path: include/modulenta/utility/pc_calibrate_piecewise_i32.h

## include/modulenta/utility/pc_cell_laplacian4_i32.h

Public API: pc_cell_laplacian4_i32

Contract: Exact four-neighbor discrete Laplacian: north+east+south+west-4*center. Returns an int64 result covering the full int32 input domain.

Header path: include/modulenta/utility/pc_cell_laplacian4_i32.h

## include/modulenta/utility/pc_cell_laplacian8_i32.h

Public API: pc_cell_laplacian8_i32

Contract: Exact unweighted Moore-neighborhood Laplacian: sum(eight neighbors)-8*center.

Header path: include/modulenta/utility/pc_cell_laplacian8_i32.h

## include/modulenta/utility/pc_counter_hysteretic_u32.h

Public API: pc_counter_hysteretic_u32

Contract: Integrate true samples up and false samples down; switch at separate thresholds.

Header path: include/modulenta/utility/pc_counter_hysteretic_u32.h

## include/modulenta/utility/pc_decimal_digit_count_u64.h

Public API: pc_decimal_digit_count_u64

Contract: Return the number of base-10 digits; zero has one digit.

Header path: include/modulenta/utility/pc_decimal_digit_count_u64.h

## include/modulenta/utility/pc_lcg_jump_u32.h

Public API: pc_lcg_jump_u32

Contract: Advance an LCG state by `steps` transitions of state = multiplier * state + increment modulo 2^32.

Header path: include/modulenta/utility/pc_lcg_jump_u32.h

## include/modulenta/utility/pc_lower_bound_i32.h

Public API: pc_lower_bound_i32

Contract: First index i with sorted[i] >= value, or count if none. Input must be nondecreasing. Null sorted is valid only for count==0; failure preserves out.

Header path: include/modulenta/utility/pc_lower_bound_i32.h

## include/modulenta/utility/pc_majority_decode3_u32.h

Public API: pc_majority_decode3_u32

Contract: Bitwise majority vote among three redundant uint32_t replicas. This is not a numerical median and does not report disagreement.

Header path: include/modulenta/utility/pc_majority_decode3_u32.h

## include/modulenta/utility/pc_midpoint_u64_safe.h

Public API: pc_midpoint_u64_safe

Contract: Return floor((a+b)/2) without overflowing the uint64 domain.

Header path: include/modulenta/utility/pc_midpoint_u64_safe.h

## include/modulenta/utility/pc_monotonic_search_i32.h

Public API: pc_monotonic_search_i32

Contract: Find first x in inclusive [lo,hi] for which predicate(x,context) is true. Predicate must be deterministic and monotone false->true. Returns API success; found=false means no match. Invalid args preserve both outputs.

Header path: include/modulenta/utility/pc_monotonic_search_i32.h

## include/modulenta/utility/pc_nearest_sorted_i32.h

Public API: pc_nearest_sorted_i32

Contract: Return index of nearest value in nondecreasing sorted[]. Equal-distance ties choose the lower value; duplicates choose their first index. False on empty/null input or null output; failure preserves *out_index.

Header path: include/modulenta/utility/pc_nearest_sorted_i32.h

## include/modulenta/utility/pc_ntc_adc_from_resistance_u32.h

Public API: pc_ntc_adc_from_resistance_u32

Contract: Ratiometric divider: fixed resistor to excitation, NTC to ground, ADC at midpoint. adc_full_scale is maximum code (not 2^N). Output code is rounded nearest-even and may equal full-scale for a finite high resistance.

Header path: include/modulenta/utility/pc_ntc_adc_from_resistance_u32.h

## include/modulenta/utility/pc_offset_to_binary_i32.h

Public API: pc_offset_to_binary_i32

Contract: Decode binary = code - offset when it fits int32_t. False for a null output or unrepresentable result; failure writes nothing.

Header path: include/modulenta/utility/pc_offset_to_binary_i32.h

## include/modulenta/utility/pc_opt_argmax_small_i32.h

Public API: pc_opt_argmax_small_i32

Contract: Return the first index of the maximum in 1..8 signed values. `index` must not overlap the input array. Invalid input leaves *index unchanged.

Header path: include/modulenta/utility/pc_opt_argmax_small_i32.h

## include/modulenta/utility/pc_opt_argmin_small_i32.h

Public API: pc_opt_argmin_small_i32

Contract: Return the first index of the minimum in 1..8 signed values. `index` must not overlap the input array. Invalid input leaves *index unchanged.

Header path: include/modulenta/utility/pc_opt_argmin_small_i32.h

## include/modulenta/utility/pc_round_robin_next_u32.h

Public API: pc_round_robin_next_u32

Contract: Advance a valid index in [0,count), wrapping to zero; reject invalid state.

Header path: include/modulenta/utility/pc_round_robin_next_u32.h

## include/modulenta/utility/pc_sensor_disagreement_i32.h

Public API: pc_sensor_disagreement_i32

Contract: Exact absolute difference; UINT32_MAX is representable for opposite extremes.

Header path: include/modulenta/utility/pc_sensor_disagreement_i32.h

## include/modulenta/utility/pc_signed_width_i32.h

Public API: pc_signed_width_i32

Contract: Minimum two's-complement bit count including sign; zero requires one bit.

Header path: include/modulenta/utility/pc_signed_width_i32.h

## include/modulenta/utility/pc_sort3_i32.h

Public API: pc_sort3_i32

Contract: Sort three caller-owned int32 values into nondecreasing order.

Header path: include/modulenta/utility/pc_sort3_i32.h

## include/modulenta/utility/pc_sort4_i32.h

Public API: pc_sort4_i32

Contract: Sort four caller-owned int32 values into nondecreasing order.

Header path: include/modulenta/utility/pc_sort4_i32.h

## include/modulenta/utility/pc_sort5_i32.h

Public API: pc_sort5_i32

Contract: Sort five caller-owned int32 values into nondecreasing order.

Header path: include/modulenta/utility/pc_sort5_i32.h

## include/modulenta/utility/pc_sort6_i32.h

Public API: pc_sort6_i32

Contract: Sort six caller-owned int32 values into nondecreasing order.

Header path: include/modulenta/utility/pc_sort6_i32.h

## include/modulenta/utility/pc_sort8_i32.h

Public API: pc_sort8_i32

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/modulenta/utility/pc_sort8_i32.h

## include/modulenta/utility/pc_span_overlap_u32.h

Public API: pc_span_overlap_u32

Contract: Test overlap of two valid half-open spans; empty/overflowing spans do not overlap.

Header path: include/modulenta/utility/pc_span_overlap_u32.h

## include/modulenta/utility/pc_splitmix32_step.h

Public API: pc_splitmix32_step

Contract: Advance a 32-bit Weyl state and return its mixed output.

Header path: include/modulenta/utility/pc_splitmix32_step.h

## include/modulenta/utility/pc_state_onehot_encode_u32.h

Public API: pc_state_onehot_encode_u32

Contract: Encode a bit index from 0 through 31 as a one-hot uint32 value.

Header path: include/modulenta/utility/pc_state_onehot_encode_u32.h

## include/modulenta/utility/pc_state_onehot_check_u32.h

Public API: pc_state_onehot_check_u32

Contract: Return true iff exactly one bit is set; zero is not one-hot.

Header path: include/modulenta/utility/pc_state_onehot_check_u32.h

## include/modulenta/utility/pc_state_onehot_index_u32.h

Public API: pc_state_onehot_index_u32

Contract: Return the index of the only set bit; reject zero and multi-bit values.

Header path: include/modulenta/utility/pc_state_onehot_index_u32.h

## include/modulenta/utility/pc_stride_offset_u32.h

Public API: pc_stride_offset_u32

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/modulenta/utility/pc_stride_offset_u32.h

## include/modulenta/utility/pc_table_nearest_index_i32.h

Public API: pc_table_nearest_index_i32

Contract: Find the closest value in an arbitrary-order table. Equal distances select the lowest table index. Invalid arguments preserve *index.

Header path: include/modulenta/utility/pc_table_nearest_index_i32.h

## include/modulenta/utility/pc_table_validate_sorted_i32.h

Public API: pc_table_validate_sorted_i32

Contract: Return true if values are nondecreasing; duplicates are allowed. An empty table is sorted and may use a null pointer.

Header path: include/modulenta/utility/pc_table_validate_sorted_i32.h

## include/modulenta/utility/pc_token_bucket_consume_u32.h

Public API: pc_token_bucket_consume_u32

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/modulenta/utility/pc_token_bucket_consume_u32.h

## include/modulenta/utility/pc_token_bucket_refill_u32.h

Public API: pc_token_bucket_refill_u32

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/modulenta/utility/pc_token_bucket_refill_u32.h
