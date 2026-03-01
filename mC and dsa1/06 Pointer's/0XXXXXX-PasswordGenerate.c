#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed random number generator with current time
    char password[5];

    for (int i = 0; i < 4; i++) {
        password[i] = (rand() % 26) + 'A';  // Generate random uppercase letter
    }
    password[4] = '\0';  // End string properly

    printf("Generated Password: %s\n", password);
    return 0;
}
