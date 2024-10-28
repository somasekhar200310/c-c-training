#include <stdio.h>

void greet() {
    printf("Hello, World!\n");
}

int main() {
    greet();
    return 0;
}

OUTPUT:
Hello,World!
------------------------------------------------------------
#include <stdio.h>

void printSum(int a, int b) {
    printf("Sum: %d\n", a + b);
}

int main() {
    printSum(5, 10);
    return 0;
}

OUTPUT:
Sum:15
-------------------------------------------------------------
#include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int result = multiply(5, 4);
    printf("Product: %d\n", result);
    return 0;
}

OUTPUT:
Product:20
--------------------------------------------------------------
#include <stdio.h>

int checkEvenOdd(int num) {
    if (num % 2 == 0) {
        return 1; // Even
    } else {
        return 0; // Odd
    }
}

int main() {
    int number = 7;
    if (checkEvenOdd(number)) {
        printf("%d is Even\n", number);
    } else {
        printf("%d is Odd\n", number);
    }
    return 0;
}

OUTPUT:
7 is Odd
