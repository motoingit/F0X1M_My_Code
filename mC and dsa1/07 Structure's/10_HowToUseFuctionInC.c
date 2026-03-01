#include <stdio.h>

struct MathOps {
    int (*add)(int, int);
    int (*mul)(int, int);
};

int addFunc(int a, int b) { return a + b; }
int mulFunc(int a, int b) { return a * b; }

int main() {
    struct MathOps ops;
    ops.add = addFunc;
    ops.mul = mulFunc;

    printf("Add: %d\n", ops.add(3, 4));
    printf("Mul: %d\n", ops.mul(3, 4));
    return 0;
}
