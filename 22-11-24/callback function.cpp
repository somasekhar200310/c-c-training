#include <iostream>

// A simple callback function
void myCallback(int value) {
    std::cout << "Callback function called with value: " << value << std::endl;
}

// Function that takes a callback as a parameter
void processData(void (*callback)(int), int data) {
    // Do some processing (simulated by printing the data)
    std::cout << "Processing data: " << data << std::endl;

    // Call the callback function with the data
    callback(data);
}

int main() {
    int data = 42;

    // Passing the callback function to processData
    processData(myCallback, data);

    return 0;
}
