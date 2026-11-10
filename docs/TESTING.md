# Testing

## Current gate

The CMake test gate contains five executables. The nearest-table differential suite runs deterministic exhaustive small-domain and 150,000 seeded cases; the argmin/argmax suites exhaustively check arrays of lengths 1-6 over values -2..2. `test_all_public_api.c` directly invokes each of the 44 public API entries with representative boundary, invalid-input, and contract checks. These direct checks are not a substitute for independent differential/property testing of every operation.

| Configuration | Result |
|---|---|
| GCC 13.3, C99 strict warnings, Debug | PASS, 5/5 |
| GCC 13.3, C99 strict warnings, Release | PASS, 5/5 |
| Clang 18.1.3, C99 strict warnings, Debug | PASS, 5/5 |
| Clang 18.1.3, C99 strict warnings, Release | PASS, 5/5 |
| MSVC 19.42, strict warnings, Debug | PASS, 5/5 |
| MSVC 19.42, strict warnings, Release | PASS, 5/5 |
| GCC 13.3, AddressSanitizer + UndefinedBehaviorSanitizer | PASS, 5/5 |
| ESP32-S3 v0.2, 240 MHz | PASS, all 44 calls completed on-device |
| GitHub Actions for current changes | NOT RUN |

Reproduce host validation with `cmake -S . -B build -DMODULENTA_BUILD_TESTS=ON -DMODULENTA_STRICT_WARNINGS=ON`, then build and run CTest. Sanitizers are run with GCC using `-fsanitize=address,undefined -fno-omit-frame-pointer`.

The repository contains preserved legacy test sources, but only the five explicitly registered CMake tests are part of the current gate. The embedded timing and size values are aggregate whole-sketch smoke measurements, not per-API or library-only costs. Stack high-water usage is not measured.