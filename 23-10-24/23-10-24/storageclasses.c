auto

#include <stdio.h>

void func() {
    int x = 10;
    printf("%d\n", x);
}

int main() {
    func();
    return 0;
}


OUTPUT:
10

-----------------------------------------------------------------
Register

#include <stdio.h>

void func() {
    register int i;
    for (i = 0; i < 5; i++) {
        printf("%d\n", i);
    }
}

int main() {
    func();
    return 0;
}


OUTPUT:
3
4
----------------------------------------------------------------
Static

#include <stdio.h>

void func() {
    static int count = 0;
    count++;
    printf("%d\n", count);
}

int main() {
    func();
    func();
    return 0;
}

OUTPUT:
1
2
----------------------------------------------------------------
Extern

#include <stdio.h>

int globalVar = 20;

void func() {
    extern int globalVar;
    printf("%d\n", globalVar);
}

int main() {
    func();
    return 0;
}

OUTPUT:
20



