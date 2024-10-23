signed integer (%d)

#include <stdio.h>

int main() {
    int i= -7;
     printf("signed integer %d\n", i);
} 


OUTPUT:
Signed Integer -7

------------------------------------------------------------

Unsigned Integer (%u)

#include <stdio.h>

int main() {
   unsigned int i= 5;
     printf("unsigned integer %u\n", i);
} 

OUTPUT:
Unsigned integer 5

--------------------------------------------------------------

String (%s)

int main() {
 
    char str[] = "I am Learning C";

    printf("String: %s\n", str);
        return 0;
}

OUTPUT:

I am Learning C
----------------------------------------------------------------
Float (%f)

int main() {
 
    float num = 3.14159;
    printf("Float: %f\n", num);
        return 0;
}

OUTPUT:
Float: 3.141590
---------------------------------------------------------------
Single Charcter (%c)


int main() {
 
     char ch = 'K';
    printf("Character: %c\n", ch);
        return 0;
}

OUTPUT:
Character: K
-----------------------------------------------------------------
Scientific notation floating-point number (%e)

int main() {
 
    double num = 123456.789;

    printf("Scientific notation : %e\n", num);
}

OUTPUT:
Scientific Notation: 1.234568e+05
----------------------------------------------------------------
Unsigned hexadecimal integer (lowercase) (%x)
Unsigned hexadecimal integer (uppercase) (%X)


int main() {
 
    unsigned int num1 = 255;
    printf("Decimal: %u, Hexadecimal (lowercase): %x\n", num1, num1);
     printf("Decimal: %u, Hexadecimal (uppercase): %X\n", num1, num1);
     return 0;
}

OUTPUT:
Decimal:255 , Hexadecimal(lowercase):ff
Decimal:255 , Hexadecimal(uppercase):FF

-----------------------------------------------------------------
Octal integer (%o)

int main() {
 
    unsigned int num1 = 255;
    printf("octal: %o\n", num1);
   
     return 0;

OUTPUT:
Octal: 377