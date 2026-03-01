#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the number of Names : ");
    scanf("%d", &n);
    getchar(); // Consume leftover newline from scanf

    char str[n][20]; // n names, each max 19 chars + '\0'

    for (int i = 0; i < n; i++) {
        printf("Enter Name %d : ", i + 1);
        fgets(str[i], 20, stdin);
        str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline
    }

    char atr[20];
    printf("Enter the Name you want to find: ");
    scanf("%[^\n]s", atr); // Read full name with spaces

    int found = 0; // Flag to check if name is found

    for (int i = 0; i < n; i++) {
        if (strcmp(atr, str[i]) == 0) { // Correct strcmp usage
            printf("Found\n");
            found = 1;
            break; // No need to check further
        }
    }

    if (!found)
        printf("Not Found\n");

    return 0;
}
