#include <stdio.h>

#define DIVIDE_BY_ZERO_ERROR -1

// Function to divide and handle division by zero
int divide(int numerator, int denominator, int* result) {
    if (denominator == 0) {
        return DIVIDE_BY_ZERO_ERROR;  // Return error code for division by zero
    }
    *result = numerator / denominator;
    return 0;  // Successful division
}

int main() {
    int numerator = 10, denominator = 0;
    int result;

    int errorCode = divide(numerator, denominator, &result);

    if (errorCode == DIVIDE_BY_ZERO_ERROR) {
        printf("Error: Division by zero\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
