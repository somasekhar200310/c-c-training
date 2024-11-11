#include <stdio.h>

// Function to divide and handle division by zero
int divide(int numerator, int denominator, int* result) {
    if (denominator == 0) {
        return -1;  // Return error code directly for division by zero
    }
    *result = numerator / denominator;
    return 0;  // Successful division
}

int main() {
    int numerator = 10, denominator = 0;
    int result;

    int errorCode = divide(numerator, denominator, &result);

    if (errorCode == -1) {
        printf("Error: Division by zero\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
