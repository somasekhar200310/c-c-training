pow

#include <stdio.h>
#include <math.h>

int main() {
    double base = 2.0;
    double exponent = 3.0;

    double result = pow(base, exponent);

    printf("%.2f raised to the power of %.2f is %.2f\n", base, exponent, result);

    return 0;
}

OUTPUT:
2 raised to power of 3 is 8
---------------------------------------------------------------
pow10

#include <stdio.h>
#include <math.h>

int main() {
    double exponent = 3.0;

    double result = pow(10.0, exponent);

    printf("10 raised to the power of %.2f is %.2f\n", exponent, result);

    return 0;
}

OUTPUT:
10 raised to power 3 is 1000

----------------------------------------------------------------
sqrt

#include <stdio.h>
#include <math.h>

int main() {
    double number = 16.0;

    double result = sqrt(number);

    printf("The square root of %.2f is %.2f\n", number, result);

    return 0;
}

OUTPUT:
The square root of 16 is 4
----------------------------------------------------------------
log 

#include <stdio.h>
#include <math.h>

int main() {
    double number = 100.0;

    double result = log(number);

    printf("The natural logarithm of %.2f is %.2f\n", number, result);

    return 0;
}

OUTPUT:
The natural logarithm of 100 is 4.61
----------------------------------------------------------------
log10

#include <stdio.h>
#include <math.h>

int main() {
    double number = 1000.0;

    double result = log10(number);

    printf("The base 10 logarithm of %.2f is %.2f\n", number, result);

    return 0;
}

OUTPUT:
The base 10 logarithm of 1000 is 3
---------------------------------------------------------------
exp

#include <stdio.h>
#include <math.h>

int main() {
    double exponent = 2.0;

    double result = exp(exponent);

    printf("The value of e raised to the power of %.2f is %.2f\n", exponent, result);

    return 0;
}

OUTPUT:
The value of e raised to the power of 2 is 7.39
-------------------------------------------------------------
fabs

#include <stdio.h>
#include <math.h>

int main() {
    double number = -5.7;

    double result = fabs(number);

    printf("The absolute value of %.2f is %.2f\n", number, result);

    return 0;
}

OUTPUT:
The absolute value of -5.70 is 5.70
------------------------------------------------------------
ceil

#include <stdio.h>
#include <math.h>

int main() {
    double number = 4.3;

    double result = ceil(number);

    printf("The ceiling of %.2f is %.2f\n", number, result);

    return 0;
}

OUTPUT:
The ceiling of 4.30 is 5.00 
