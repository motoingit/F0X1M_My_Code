#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];  // Stores user input
    char flag1[] = "close";
    char op;
    int num1, num2, result;

    while (1) {
        printf("Enter your Expression (or type 'close' to exit): ");
        fgets(str, sizeof(str), stdin);  // Read the full input including spaces
        str[strcspn(str, "\n")] = 0;     // Remove newline character

        if (strcmp(str, flag1) == 0) { // Check if user wants to exit
            printf("Calculator Closed.\n");
            break;
        }

        // Parse input using sscanf (supports format like: 12 + 5)
        if (sscanf(str, "%d %c %d", &num1, &op, &num2) != 3) {
            printf("Invalid input! Please use format: num1 operator num2\n");
            continue;
        }

        // Perform Calculation
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 == 0) {
                    printf("Error! Division by zero is not allowed.\n");
                    continue;
                }
                result = num1 / num2; 
                break;
            default: 
                printf("Invalid operator! Use +, -, *, /\n");
                continue;
        }

        // Display result
        printf("%d %c %d = %d\n", num1, op, num2, result);
    }

    return 0;
}
