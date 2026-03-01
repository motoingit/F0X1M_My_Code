
/* Question : Is inheritence in c possible
  ans: not natively but yes, SEE YOURSELF >
*/

#include <stdio.h>

// The "base" struct
typedef struct {
    int x;
} Base;

// The "derived" struct, with Base as its first member
typedef struct {
    Base base;
    int y;
} Derived;

void display_base(Base *b) {
    printf("Base: %d\n", b->x);
}

int main() {
    Derived d;
    d.base.x = 10;
    d.y = 20;

    // Cast the derived pointer to a base pointer
    display_base((Base*)&d);

    return 0;
}