# Performance

A smoke workload on an ESP32-S3 v0.2 (240 MHz) called the boundary suite for all 44 public operations 1,000 times. It observed 9,225,240 cycle-counter ticks total, or 9,225 ticks per complete suite run (integer average). The workload includes test/control flow and reports one aggregate figure; it is not a per-function benchmark and may include interrupt/runtime effects.

The Arduino ESP32 3.3.10 build for the Ozobot DRVKit profile reported 300,405 bytes of whole-sketch program storage and 21,756 bytes of global variables (6% of the configured 327,680-byte internal RAM). These totals include the Arduino runtime and test harness; they are not library-only flash or RAM figures. Stack high-water usage was not measured. No before/after optimization comparison was performed.