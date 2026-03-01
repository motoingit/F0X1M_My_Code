#include <stdio.h>
int main() {
    char a[50];

    printf("Enter a string: ");
    gets(a);  // Unsafe, but included for demonstration

    printf("You entered: ");
    puts(a);  // Prints the string


    ///////////////////////////////////////////////////////////////////////////////////////////


    printf("Enter a string: ");
    fgets(a, sizeof(a), stdin);  // Safer input method

    printf("You entered: ");
    puts(a);
    return 0;
}
// Why fgets() is Better Than gets()?
// ✅ Prevents buffer overflow by limiting input size.
// ✅ Safer for real-world applications since it avoids memory corruption.
// ✅ Handles spaces in input properly.