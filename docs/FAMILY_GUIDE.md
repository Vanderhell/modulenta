# Modulenta family guide

## What this family solves

**Embedded utility operations.** Bounded indexing, representation transforms, selection, compact state and token helpers.

This guide describes the complete public family as an independent embedded-C product. Each primitive remains separately linkable; select only the headers and source units required by the application.

## When to use this family

Use Modulenta when the application needs the operations listed below and requires deterministic behavior, explicit caller-owned memory, and no mandatory operating-system services.

## Family at a glance

```mermaid
flowchart LR
    A[Application input] --> B[Validate representation and bounds]
    B --> C[Select one public primitive]
    C --> D[Check status or output contract]
    D --> E[Use result with documented units]
```

## Primitive map

| Public header | Symbol | Purpose and contract | Validation source |
|---|---|---|---|
| `include/modulenta/utility/pc_accumulate_product_i32.h` | `pc_accumulate_product_i32` | Add a*b exactly to *accumulator; signed overflow leaves it unchanged. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_accumulate_square_i32.h` | `pc_accumulate_square_i32` | Add value squared to *accumulator; overflow leaves it unchanged. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_adc_oversample_accumulate_u32.h` | `pc_adc_oversample_accumulate_u32` | Add one ADC code to a caller-owned uint64 sum. Overflow/null fails atomically. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_approx_uniform_knots_u32.h` | `pc_approx_uniform_knots_u32` | Fill knot_count strictly increasing sample indices spanning [0, sample_count - 1], distributed by floor(i*(sample_count-1)/ (knot_count-1)). Requires 2 <= knot_count <= sample_count. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_arithmetic_sequence_sum_i32.h` | `pc_arithmetic_sequence_sum_i32` | Sum count terms start + i*step, i=0..count-1. Every term must fit int32. Returns exact int64 sum; count zero returns zero. False leaves sum unchanged. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_binary_centroid_accum_i32.h` | `pc_binary_centroid_accum_i32` | Zero-initialize; each update adds one foreground pixel coordinate. Sums/count encode the exact rational centroid; false leaves state unchanged. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_binary_majority3x3_u32.h` | `pc_binary_majority3x3_u32` | Low 9 bits encode a complete 3x3 neighborhood, row-major; output is 0/1. False for high bits or null result; failure preserves *result. | tests/test_binary_majority3x3_u32.c |
| `include/modulenta/utility/pc_binary_run_horizontal_u32.h` | `pc_binary_run_horizontal_u32` | Count consecutive nonzero row samples from start_x to the first zero or width. start_x==width returns zero. Invalid arguments preserve *run_length. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_binary_to_offset_i32.h` | `pc_binary_to_offset_i32` | Encode signed binary as code = binary + offset in uint32 range. False for a null output or unrepresentable code; failure writes nothing. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_binary_width_u32.h` | `pc_binary_width_u32` | Return the number of significant binary digits; zero has width zero. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_bswap64_u64.h` | `pc_bswap64_u64` | Reverse the eight byte positions in a uint64 value. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_calibrate_piecewise_i32.h` | `pc_calibrate_piecewise_i32` | Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_cell_laplacian4_i32.h` | `pc_cell_laplacian4_i32` | Exact four-neighbor discrete Laplacian: north+east+south+west-4*center. Returns an int64 result covering the full int32 input domain. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_cell_laplacian8_i32.h` | `pc_cell_laplacian8_i32` | Exact unweighted Moore-neighborhood Laplacian: sum(eight neighbors)-8*center. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_counter_hysteretic_u32.h` | `pc_counter_hysteretic_u32` | Integrate true samples up and false samples down; switch at separate thresholds. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_decimal_digit_count_u64.h` | `pc_decimal_digit_count_u64` | Return the number of base-10 digits; zero has one digit. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_lcg_jump_u32.h` | `pc_lcg_jump_u32` | Advance an LCG state by `steps` transitions of state = multiplier * state + increment modulo 2^32. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_lower_bound_i32.h` | `pc_lower_bound_i32` | First index i with sorted[i] >= value, or count if none. Input must be nondecreasing. Null sorted is valid only for count==0; failure preserves out. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_majority_decode3_u32.h` | `pc_majority_decode3_u32` | Bitwise majority vote among three redundant uint32_t replicas. This is not a numerical median and does not report disagreement. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_midpoint_u64_safe.h` | `pc_midpoint_u64_safe` | Return floor((a+b)/2) without overflowing the uint64 domain. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_monotonic_search_i32.h` | `pc_monotonic_search_i32` | Find first x in inclusive [lo,hi] for which predicate(x,context) is true. Predicate must be deterministic and monotone false->true. Returns API success; found=false means no match. Invalid args preserve both outputs. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_nearest_sorted_i32.h` | `pc_nearest_sorted_i32` | Return index of nearest value in nondecreasing sorted[]. Equal-distance ties choose the lower value; duplicates choose their first index. False on empty/null input or null output; failure preserves *out_index. | tests/test_existing_composition.c |
| `include/modulenta/utility/pc_ntc_adc_from_resistance_u32.h` | `pc_ntc_adc_from_resistance_u32` | Ratiometric divider: fixed resistor to excitation, NTC to ground, ADC at midpoint. adc_full_scale is maximum code (not 2^N). Output code is rounded nearest-even and may equal full-scale for a finite high resistance. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_offset_to_binary_i32.h` | `pc_offset_to_binary_i32` | Decode binary = code - offset when it fits int32_t. False for a null output or unrepresentable result; failure writes nothing. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_opt_argmax_small_i32.h` | `pc_opt_argmax_small_i32` | Return the first index of the maximum in 1..8 signed values. `index` must not overlap the input array. Invalid input leaves *index unchanged. | tests/test_opt_argmax_small_i32.c |
| `include/modulenta/utility/pc_opt_argmin_small_i32.h` | `pc_opt_argmin_small_i32` | Return the first index of the minimum in 1..8 signed values. `index` must not overlap the input array. Invalid input leaves *index unchanged. | tests/test_opt_argmin_small_i32.c |
| `include/modulenta/utility/pc_round_robin_next_u32.h` | `pc_round_robin_next_u32` | Advance a valid index in [0,count), wrapping to zero; reject invalid state. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_sensor_disagreement_i32.h` | `pc_sensor_disagreement_i32` | Exact absolute difference; UINT32_MAX is representable for opposite extremes. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_signed_width_i32.h` | `pc_signed_width_i32` | Minimum two's-complement bit count including sign; zero requires one bit. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_sort3_i32.h` | `pc_sort3_i32` | Sort three caller-owned int32 values into nondecreasing order. | tests/test_sort3.c |
| `include/modulenta/utility/pc_sort4_i32.h` | `pc_sort4_i32` | Sort four caller-owned int32 values into nondecreasing order. | tests/test_sort4.c |
| `include/modulenta/utility/pc_sort5_i32.h` | `pc_sort5_i32` | Sort five caller-owned int32 values into nondecreasing order. | tests/test_sort5.c |
| `include/modulenta/utility/pc_sort6_i32.h` | `pc_sort6_i32` | Sort six caller-owned int32 values into nondecreasing order. | tests/test_sort6.c |
| `include/modulenta/utility/pc_sort8_i32.h` | `pc_sort8_i32` | The public header contains the authoritative signature and input/output contract. | tests/test_sort8.c |
| `include/modulenta/utility/pc_span_overlap_u32.h` | `pc_span_overlap_u32` | Test overlap of two valid half-open spans; empty/overflowing spans do not overlap. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_splitmix32_step.h` | `pc_splitmix32_step` | Advance a 32-bit Weyl state and return its mixed output. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_state_onehot_encode_u32.h` | `pc_state_onehot_encode_u32` | Encode a bit index from 0 through 31 as a one-hot uint32 value. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_state_onehot_check_u32.h` | `pc_state_onehot_check_u32` | Return true iff exactly one bit is set; zero is not one-hot. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_state_onehot_index_u32.h` | `pc_state_onehot_index_u32` | Return the index of the only set bit; reject zero and multi-bit values. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_stride_offset_u32.h` | `pc_stride_offset_u32` | The public header contains the authoritative signature and input/output contract. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_table_nearest_index_i32.h` | `pc_table_nearest_index_i32` | Find the closest value in an arbitrary-order table. Equal distances select the lowest table index. Invalid arguments preserve *index. | tests/test_nearest.c |
| `include/modulenta/utility/pc_table_validate_sorted_i32.h` | `pc_table_validate_sorted_i32` | Return true if values are nondecreasing; duplicates are allowed. An empty table is sorted and may use a null pointer. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_token_bucket_consume_u32.h` | `pc_token_bucket_consume_u32` | The public header contains the authoritative signature and input/output contract. | tests/test_all_public_api.c (direct boundary checks) |
| `include/modulenta/utility/pc_token_bucket_refill_u32.h` | `pc_token_bucket_refill_u32` | The public header contains the authoritative signature and input/output contract. | tests/test_all_public_api.c (direct boundary checks) |

## Selection guidance

- Choose the primitive whose width, representation, rounding, saturation, wrapping, and error contract match the application.
- Do not substitute a similarly named function without checking the public header.
- Allocate state and buffers in the caller; respect documented aliasing and output-preservation rules.
- Treat entries marked without a validation source as requiring additional product-level tests before release.

## Integration checklist

1. Include only the required public header.
2. Compile the matching source translation unit or use the product CMake target.
3. Check every boolean/status return before consuming an output.
4. Add application-specific boundary tests for units, widths, invalid inputs, and overflow behavior.
5. Run the documented host tests before target integration.

## Complexity and footprint

The product is split into independent translation units. Exact flash, RAM, stack, and cycle costs depend on the selected functions, compiler, optimization, and MCU; unmeasured values remain explicitly marked PENDING in the testing documentation.

## Validation boundary

The API reference links each public entry to its implementation and available validation source. Hardware status is reported only when reproducible target evidence exists.
