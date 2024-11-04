struct padding

#include <stdio.h>

struct PackedData {
    char a;      // 1 byte
    int b;       // 4 bytes
    char c;      // 1 byte
};

struct AlignedData {
    char a;      // 1 byte
    char c;      // 1 byte
    int b;       // 4 bytes
};

int main() {
    printf("Size of PackedData: %zu bytes\n", sizeof(struct PackedData));
    printf("Size of AlignedData: %zu bytes\n", sizeof(struct AlignedData));

    return 0;
}

OUTPUT:
Size of PackedData: 12 bytes
Size of AlignedData: 8 bytes