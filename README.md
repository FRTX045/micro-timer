# Execution Time Measurement Utility

This repository contains a C++ utility function that measures the execution time of any callable (function, lambda, functor, etc.) with microsecond precision.

## Usage

1. Include the `measure_time.hpp` header file in your C++ source file.
2. Call the `measure_time` function with the callable and its arguments.

```cpp
#include "measure_time.hpp"

int main() {
    // Example function to measure
    auto expensive_function = []() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    };

    auto time_taken = measure_time(expensive_function);
    std::cout << "Time taken: " << time_taken << " microseconds" << std::endl;

    return 0;
}
