# Modulenta API reference

This reference explains every public header in the Modulenta product. It is generated from the current headers and test sources; the header remains authoritative when a detail conflicts.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and a call extracted from the validating test source. The examples are evidence-oriented; adapt buffer ownership and numeric units to the application.

## include/modulenta/utility/pc_accumulate_product_i32.h

**Public symbol:** pc_accumulate_product_i32

**Implementation unit:** src/pc_accumulate_product_i32.c

**Purpose and contract:** Add a*b exactly to *accumulator; signed overflow leaves it unchanged.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_accumulate_square_i32.h

**Public symbol:** pc_accumulate_square_i32

**Implementation unit:** src/pc_accumulate_square_i32.c

**Purpose and contract:** Add value squared to *accumulator; overflow leaves it unchanged.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_adc_oversample_accumulate_u32.h

**Public symbol:** pc_adc_oversample_accumulate_u32

**Implementation unit:** src/pc_adc_oversample_accumulate_u32.c

**Purpose and contract:** Add one ADC code to a caller-owned uint64 sum. Overflow/null fails atomically.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_approx_uniform_knots_u32.h

**Public symbol:** pc_approx_uniform_knots_u32

**Implementation unit:** src/pc_approx_uniform_knots_u32.c

**Purpose and contract:** Fill knot_count strictly increasing sample indices spanning [0, sample_count - 1], distributed by floor(i*(sample_count-1)/ (knot_count-1)). Requires 2 <= knot_count <= sample_count.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_arithmetic_sequence_sum_i32.h

**Public symbol:** pc_arithmetic_sequence_sum_i32

**Implementation unit:** src/pc_arithmetic_sequence_sum_i32.c

**Purpose and contract:** Sum count terms start + i*step, i=0..count-1. Every term must fit int32. Returns exact int64 sum; count zero returns zero. False leaves sum unchanged.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_binary_centroid_accum_i32.h

**Public symbol:** pc_binary_centroid_accum_i32

**Implementation unit:** src/pc_binary_centroid_accum_i32.c

**Purpose and contract:** Zero-initialize; each update adds one foreground pixel coordinate. Sums/count encode the exact rational centroid; false leaves state unchanged.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_binary_majority3x3_u32.h

**Public symbol:** pc_binary_majority3x3_u32

**Implementation unit:** src/pc_binary_majority3x3_u32.c

**Purpose and contract:** Low 9 bits encode a complete 3x3 neighborhood, row-major; output is 0/1. False for high bits or null result; failure preserves *result.

**Validation source:** tests/test_binary_majority3x3_u32.c

**Test-derived call:**
```c
pc_binary_majority3x3_u32(m,&out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_binary_run_horizontal_u32.h

**Public symbol:** pc_binary_run_horizontal_u32

**Implementation unit:** src/pc_binary_run_horizontal_u32.c

**Purpose and contract:** Count consecutive nonzero row samples from start_x to the first zero or width. start_x==width returns zero. Invalid arguments preserve *run_length.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_binary_to_offset_i32.h

**Public symbol:** pc_binary_to_offset_i32

**Implementation unit:** src/pc_binary_to_offset_i32.c

**Purpose and contract:** Encode signed binary as code = binary + offset in uint32 range. False for a null output or unrepresentable code; failure writes nothing.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_binary_width_u32.h

**Public symbol:** pc_binary_width_u32

**Implementation unit:** src/pc_binary_width_u32.c

**Purpose and contract:** Return the number of significant binary digits; zero has width zero.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_bswap64_u64.h

**Public symbol:** pc_bswap64_u64

**Implementation unit:** src/pc_bswap64_u64.c

**Purpose and contract:** Reverse the eight byte positions in a uint64 value.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_calibrate_piecewise_i32.h

**Public symbol:** pc_calibrate_piecewise_i32

**Implementation unit:** src/pc_calibrate_piecewise_i32.c

**Purpose and contract:** Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_cell_laplacian4_i32.h

**Public symbol:** pc_cell_laplacian4_i32

**Implementation unit:** src/pc_cell_laplacian4_i32.c

**Purpose and contract:** Exact four-neighbor discrete Laplacian: north+east+south+west-4*center. Returns an int64 result covering the full int32 input domain.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_cell_laplacian8_i32.h

**Public symbol:** pc_cell_laplacian8_i32

**Implementation unit:** src/pc_cell_laplacian8_i32.c

**Purpose and contract:** Exact unweighted Moore-neighborhood Laplacian: sum(eight neighbors)-8*center.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_counter_hysteretic_u32.h

**Public symbol:** pc_counter_hysteretic_u32

**Implementation unit:** src/pc_counter_hysteretic_u32.c

**Purpose and contract:** Integrate true samples up and false samples down; switch at separate thresholds.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_decimal_digit_count_u64.h

**Public symbol:** pc_decimal_digit_count_u64

**Implementation unit:** src/pc_decimal_digit_count_u64.c

**Purpose and contract:** Return the number of base-10 digits; zero has one digit.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_lcg_jump_u32.h

**Public symbol:** pc_lcg_jump_u32

**Implementation unit:** src/pc_lcg_jump_u32.c

**Purpose and contract:** Advance an LCG state by `steps` transitions of state = multiplier * state + increment modulo 2^32.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_lower_bound_i32.h

**Public symbol:** pc_lower_bound_i32

**Implementation unit:** src/pc_lower_bound_i32.c

**Purpose and contract:** First index i with sorted[i] >= value, or count if none. Input must be nondecreasing. Null sorted is valid only for count==0; failure preserves out.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_majority_decode3_u32.h

**Public symbol:** pc_majority_decode3_u32

**Implementation unit:** src/pc_majority_decode3_u32.c

**Purpose and contract:** Bitwise majority vote among three redundant uint32_t replicas. This is not a numerical median and does not report disagreement.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_midpoint_u64_safe.h

**Public symbol:** pc_midpoint_u64_safe

**Implementation unit:** src/pc_midpoint_u64_safe.c

**Purpose and contract:** Return floor((a+b)/2) without overflowing the uint64 domain.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_monotonic_search_i32.h

**Public symbol:** pc_monotonic_search_i32

**Implementation unit:** src/pc_monotonic_search_i32.c

**Purpose and contract:** Find first x in inclusive [lo,hi] for which predicate(x,context) is true. Predicate must be deterministic and monotone false->true. Returns API success; found=false means no match. Invalid args preserve both outputs.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_nearest_sorted_i32.h

**Public symbol:** pc_nearest_sorted_i32

**Implementation unit:** src/pc_nearest_sorted_i32.c

**Purpose and contract:** Return index of nearest value in nondecreasing sorted[]. Equal-distance ties choose the lower value; duplicates choose their first index. False on empty/null input or null output; failure preserves *out_index.

**Validation source:** tests/test_existing_composition.c

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_ntc_adc_from_resistance_u32.h

**Public symbol:** pc_ntc_adc_from_resistance_u32

**Implementation unit:** src/pc_ntc_adc_from_resistance_u32.c

**Purpose and contract:** Ratiometric divider: fixed resistor to excitation, NTC to ground, ADC at midpoint. adc_full_scale is maximum code (not 2^N). Output code is rounded nearest-even and may equal full-scale for a finite high resistance.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_offset_to_binary_i32.h

**Public symbol:** pc_offset_to_binary_i32

**Implementation unit:** src/pc_offset_to_binary_i32.c

**Purpose and contract:** Decode binary = code - offset when it fits int32_t. False for a null output or unrepresentable result; failure writes nothing.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_opt_argmax_small_i32.h

**Public symbol:** pc_opt_argmax_small_i32

**Implementation unit:** src/pc_opt_argmax_small_i32.c

**Purpose and contract:** Return the first index of the maximum in 1..8 signed values. `index` must not overlap the input array. Invalid input leaves *index unchanged.

**Validation source:** tests/test_opt_argmax_small_i32.c

**Test-derived call:**
```c
pc_opt_argmax_small_i32(values,(uint8_t)n,&index\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_opt_argmin_small_i32.h

**Public symbol:** pc_opt_argmin_small_i32

**Implementation unit:** src/pc_opt_argmin_small_i32.c

**Purpose and contract:** Return the first index of the minimum in 1..8 signed values. `index` must not overlap the input array. Invalid input leaves *index unchanged.

**Validation source:** tests/test_opt_argmin_small_i32.c

**Test-derived call:**
```c
pc_opt_argmin_small_i32(values,(uint8_t)n,&index\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_round_robin_next_u32.h

**Public symbol:** pc_round_robin_next_u32

**Implementation unit:** src/pc_round_robin_next_u32.c

**Purpose and contract:** Advance a valid index in [0,count), wrapping to zero; reject invalid state.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_sensor_disagreement_i32.h

**Public symbol:** pc_sensor_disagreement_i32

**Implementation unit:** src/pc_sensor_disagreement_i32.c

**Purpose and contract:** Exact absolute difference; UINT32_MAX is representable for opposite extremes.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_signed_width_i32.h

**Public symbol:** pc_signed_width_i32

**Implementation unit:** src/pc_signed_width_i32.c

**Purpose and contract:** Minimum two's-complement bit count including sign; zero requires one bit.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_sort3_i32.h

**Public symbol:** pc_sort3_i32

**Implementation unit:** src/pc_sort3_i32.c

**Purpose and contract:** Sort three caller-owned int32 values into nondecreasing order.

**Validation source:** tests/test_sort3.c

**Test-derived call:**
```c
pc_sort3_i32(NULL\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_sort4_i32.h

**Public symbol:** pc_sort4_i32

**Implementation unit:** src/pc_sort4_i32.c

**Purpose and contract:** Sort four caller-owned int32 values into nondecreasing order.

**Validation source:** tests/test_sort4.c

**Test-derived call:**
```c
pc_sort4_i32(NULL\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_sort5_i32.h

**Public symbol:** pc_sort5_i32

**Implementation unit:** src/pc_sort5_i32.c

**Purpose and contract:** Sort five caller-owned int32 values into nondecreasing order.

**Validation source:** tests/test_sort5.c

**Test-derived call:**
```c
pc_sort5_i32(NULL\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_sort6_i32.h

**Public symbol:** pc_sort6_i32

**Implementation unit:** src/pc_sort6_i32.c

**Purpose and contract:** Sort six caller-owned int32 values into nondecreasing order.

**Validation source:** tests/test_sort6.c

**Test-derived call:**
```c
pc_sort6_i32(values\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_sort8_i32.h

**Public symbol:** pc_sort8_i32

**Implementation unit:** src/pc_sort8_i32.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** tests/test_sort8.c

**Test-derived call:**
```c
pc_sort8_i32(v\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_span_overlap_u32.h

**Public symbol:** pc_span_overlap_u32

**Implementation unit:** src/pc_span_overlap_u32.c

**Purpose and contract:** Test overlap of two valid half-open spans; empty/overflowing spans do not overlap.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_splitmix32_step.h

**Public symbol:** pc_splitmix32_step

**Implementation unit:** src/pc_splitmix32_step.c

**Purpose and contract:** Advance a 32-bit Weyl state and return its mixed output.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_state_onehot_encode_u32.h

**Public symbol:** pc_state_onehot_encode_u32

**Implementation unit:** src/pc_state_onehot_encode_u32.c

**Purpose and contract:** Encode a bit index from 0 through 31 as a one-hot uint32 value.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_state_onehot_check_u32.h

**Public symbol:** pc_state_onehot_check_u32

**Implementation unit:** src/pc_state_onehot_check_u32.c

**Purpose and contract:** Return true iff exactly one bit is set; zero is not one-hot.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_state_onehot_index_u32.h

**Public symbol:** pc_state_onehot_index_u32

**Implementation unit:** src/pc_state_onehot_index_u32.c

**Purpose and contract:** Return the index of the only set bit; reject zero and multi-bit values.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_stride_offset_u32.h

**Public symbol:** pc_stride_offset_u32

**Implementation unit:** src/pc_stride_offset_u32.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_table_nearest_index_i32.h

**Public symbol:** pc_table_nearest_index_i32

**Implementation unit:** src/pc_table_nearest_index_i32.c

**Purpose and contract:** Find the closest value in an arbitrary-order table. Equal distances select the lowest table index. Invalid arguments preserve *index.

**Validation source:** tests/test_nearest.c

**Test-derived call:**
```c
pc_table_nearest_index_i32(values, n, query, &got\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_table_validate_sorted_i32.h

**Public symbol:** pc_table_validate_sorted_i32

**Implementation unit:** src/pc_table_validate_sorted_i32.c

**Purpose and contract:** Return true if values are nondecreasing; duplicates are allowed. An empty table is sorted and may use a null pointer.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_token_bucket_consume_u32.h

**Public symbol:** pc_token_bucket_consume_u32

**Implementation unit:** src/pc_token_bucket_consume_u32.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/modulenta/utility/pc_token_bucket_refill_u32.h

**Public symbol:** pc_token_bucket_refill_u32

**Implementation unit:** src/pc_token_bucket_refill_u32.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** tests/test_all_public_api.c (direct boundary checks).

**Test coverage:** boundary and contract assertions are in `tests/test_all_public_api.c`.

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

