#include <iostream>
#include <chrono>
#include <thread>

// Function to measure execution time
template <typename Func, typename... Args>
auto measure_time(Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...); // Invoke the callable directly
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main() {
    // Example function to measure
    auto expensive_function = []() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    };

    auto time_taken = measure_time(expensive_function);
    std::cout << "Time taken: " << time_taken << " microseconds" << std::endl;

    return 0;
}
