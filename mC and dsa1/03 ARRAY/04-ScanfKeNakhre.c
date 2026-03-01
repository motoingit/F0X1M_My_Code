///////////nakhra bada//////////////////%s then only first word will be printed    
#include <stdio.h>

int main() {
    char a[20];

    printf("Enter a string: ");
    scanf("%s", a);  // Reads input only until the first space

    printf("Entered string is: %s", a);

    return 0;
}







///////Nakhra chota//////////////////////%[^\n] then full string will be printed
#include <stdio.h>

int main() {
    char a[20];

    printf("Enter a string: ");
    scanf("%[^\n]", a);  // Read input including spaces

    printf("Entered string is: %s", a);

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////