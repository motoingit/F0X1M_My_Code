#include <stdio.h>

int main() {
    int x = 5;  // 0101 in binary
    int y = 3;  // 0011 in binary

    printf("x = %d (Binary: 0101)\n", x);
    printf("y = %d (Binary: 0011)\n\n", y);

    printf("Bitwise AND (x & y)  = %d\n", x & y);   // 0001 -> 1
    printf("Bitwise OR  (x | y)  = %d\n", x | y);   // 0111 -> 7
    printf("Bitwise XOR (x ^ y)  = %d\n", x ^ y);   // 0110 -> 6
    printf("Bitwise NAND ~(x & y) = %d\n", ~(x & y)); // 1110 (-2 in 2's complement)
    printf("Bitwise NOR ~(x | y)  = %d\n", ~(x | y)); // 1000 (-8 in 2's complement)
    printf("Bitwise XNOR ~(x ^ y) = %d\n", ~(x ^ y)); // 1001 (-7 in 2's complement)

    return 0;
}
