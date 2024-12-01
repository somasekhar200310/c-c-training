#include <iostream>
#include <thread>
#include <vector>

int counter = 0;  // Shared resource

// Function that increments the counter
void incrementCounter() {
    for (int i = 0; i < 100000; ++i) {
        counter++;  // Incrementing the shared counter
    }
}

int main() {
    std::vector<std::thread> threads;

    // Create 10 threads, all incrementing the shared counter
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(incrementCounter));
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    // Print the final value of the counter
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
