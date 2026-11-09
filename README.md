# modulenta

Modulenta is a standalone C99 embedded utility library for bounded indexing, representation transforms, deterministic selection, small combinatorics and compact state helpers.

## Scope

The package contains 253 public headers and 44 implementation units. It is portable C99, uses no mandatory heap or operating-system service, and keeps caller-owned state explicit where applicable.

## Build and test

```sh
cmake -S . -B build -DMODULENTA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## Validation status

Host validation is run during extraction. ESP32-S3 validation and isolated footprint measurements are pending unless explicitly recorded; no hardware result is claimed.

## Name and origin

Modulenta combines modulus (bounded relation) with lenta (measured, deliberate operation), reflecting small predictable utility transformations.
Its technical scope is bounded utility and representation helpers.

## License

Apache License 2.0, copyright Vanderhell. See LICENSE and NOTICE.
