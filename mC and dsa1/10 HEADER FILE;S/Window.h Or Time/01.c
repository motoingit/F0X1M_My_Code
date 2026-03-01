#include <stdio.h>
#include <windows.h> // For Sleep() - milliseconds

int main(){
    printf("Loading started...\n");
    int duration = 10; // seconds

    for (int i = 0; i < duration; i++) {
        printf(".");
        // fflush(stdout); // Make sure the dot is printed immediately
        Sleep(1000); // Pauses for 1000 milliseconds (1 second) for Windows
    }
    printf("\nLoading complete after %d seconds!\n", duration);
    return 0;
}
