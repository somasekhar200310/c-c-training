strlen

#include <stdio.h>
#include <string.h> 

int main() {
    const char *str = "Hello, World!"; 
    size_t length = strlen(str); 

    printf("The length of the string \"%s\" is %zu.\n", str, length); 

    return 0;
}

OUTPUT:

The Length Of the string "Hello,World!" is 13.


---------------------------------------------------------------------------------
strcpy

#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[50];

    strcpy(destination, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}

OUTPUT:

Source: Hello,World!
Destination: Hello,World!

----------------------------------------------------------------------------------
strcat

#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, ";
    char str2[] = "World!";

    strcat(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}

OUTPUT:

Concatenated string: Hello, World!

-----------------------------------------------------------------------------------
strcmp


#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";

    int result = strcmp(str1, str2);

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
"Hello" is less than "World"
--------------------------------------------------------------------------------
strchr

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char ch = 'o';

    char *result = strchr(str, ch);

    if (result) {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}

OUTPUT:
Character 'o' found at position:4

-------------------------------------------------------------------------------------
strstr

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char *substr = "World";

    char *result = strstr(str, substr);

    if (result) {
        printf("Substring \"%s\" found at position: %ld\n", substr, result - str);
    } else {
        printf("Substring \"%s\" not found.\n", substr);
    }

    return 0;
}

OUTPUT:
Substring "World" found at position :7






