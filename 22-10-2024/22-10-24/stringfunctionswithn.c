strncpy

#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[50];

    strncpy(destination, source, 5);
    destination[5] = '\0';

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}

OUTPUT:
Source: Hello, World!
Destination: Hello

----------------------------------------------------------------
strncmp

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, everyone!";

    int result = strncmp(str1, str2, 5);

    if (result < 0) {
        printf("\"%s\" is less than \"%s\"\n", str1, str2);
    } else if (result > 0) {
        printf("\"%s\" is greater than \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" is equal to \"%s\"\n", str1, str2);
    }

    return 0;
}


OUTPUT:

"Hello,World!" is equal to "Hello,everyone!"

----------------------------------------------------------------
strcat

#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Goodbye, ";
    char str2[] = "cruel World!";

    strcat(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}

OUTPUT:
Concatenated string: Goodbye, cruel World!

----------------------------------------------------------------
strtok

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! This is a test.";
    char *token;

    token = strtok(str, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}

OUTPUT:
a
test.
