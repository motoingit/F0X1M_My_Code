#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a; // Pointer to 'a'
        
    
    // void is not just changing, == but its making the thing what printf expect !!
    printf("Value of a: %d\n", a);
    printf("Address of a (&a): %p\n", &a); 
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr);

    
    printf("Value stored in ptr (address of a): %p\n", ptr);
    printf("Address of ptr (&ptr): %p\n", &ptr);

    return 0;
}
