//Write a program that generates the name of a number based on the inputted number.
#include <stdio.h>
#include <string.h> // Required for strcpy, strcat, strlen

// Arrays for number names
const char *units[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
const char *teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const char *tens[]  = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

// Function to convert a number less than 1000 to words
// Appends the word representation to the buffer.
void convertLessThanOneThousand(int num, char *buffer) {
    buffer[0] = '\0'; // Initialize buffer for this segment

    if (num >= 100) {
        strcat(buffer, units[num / 100]);
        strcat(buffer, " Hundred");
        num %= 100;
        if (num > 0) { // Add space if there's more to come (tens/units)
            strcat(buffer, " ");
        }
    }

    if (num >= 10 && num <= 19) {
        strcat(buffer, teens[num - 10]);
    } else if (num >= 20) {
        strcat(buffer, tens[num / 10]);
        if (num % 10 > 0) { // If there's a unit digit
            strcat(buffer, " ");
            strcat(buffer, units[num % 10]);
        }
    } else if (num > 0) { // For numbers 1-9 (or remaining units after hundreds)
        strcat(buffer, units[num]);
    }
}

// Main function to convert a number to its word representation
void numberToWords(long long int n, char *words_output) {
    if (n == 0) {
        strcpy(words_output, "Zero");
        return;
    }

    words_output[0] = '\0'; // Initialize the output string

    char segment_buffer[200]; // Buffer for words of a segment (e.g., "One Hundred Twenty Three")
    int add_space_before_next_segment = 0;

    // Crores (1,00,00,000)
    if (n / 10000000 > 0) {
        convertLessThanOneThousand(n / 10000000, segment_buffer);
        strcat(words_output, segment_buffer);
        strcat(words_output, " Crore");
        n %= 10000000;
        add_space_before_next_segment = 1;
    }

    // Lakhs (1,00,000)
    if (n / 100000 > 0) {
        if (add_space_before_next_segment) {
            strcat(words_output, " ");
        }
        convertLessThanOneThousand(n / 100000, segment_buffer);
        strcat(words_output, segment_buffer);
        strcat(words_output, " Lakh");
        n %= 100000;
        add_space_before_next_segment = 1;
    }

    // Thousands (1,000)
    if (n / 1000 > 0) {
        if (add_space_before_next_segment) {
            strcat(words_output, " ");
        }
        convertLessThanOneThousand(n / 1000, segment_buffer);
        strcat(words_output, segment_buffer);
        strcat(words_output, " Thousand");
        n %= 1000;
        add_space_before_next_segment = 1;
    }

    // Remaining part (less than 1000)
    if (n > 0) {
        if (add_space_before_next_segment) {
            strcat(words_output, " ");
        }
        convertLessThanOneThousand(n, segment_buffer);
        strcat(words_output, segment_buffer);
    }
}

int main() {
    long long int number; // Use long long int for numbers up to 1 crore
    char words[1000];     // Buffer to store the word representation
    printf("Enter a number (0 - 10,000,000): "); // 1 Crore = 10,000,000

    // Read the integer input
    if (scanf("%lld", &number) != 1) {
        // If scanf fails to read an integer, it means the input was not a valid number.
        // We clear the input buffer to prevent issues with subsequent inputs.
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Clear remaining characters
        printf("Invalid input. Please enter a whole number between 0 and 9.\n");
        printf("Invalid input. Please enter a whole number.\n");
        return 1; // Indicate an error
    }

    // Use a switch statement to print the name of the number
    switch (number) {
        case 0:
            printf("The name of the number is: Zero\n");
            break;
        case 1:
            printf("The name of the number is: One\n");
            break;
        case 2:
            printf("The name of the number is: Two\n");
            break;
        case 3:
            printf("The name of the number is: Three\n");
            break;
        case 4:
            printf("The name of the number is: Four\n");
            break;
        case 5:
            printf("The name of the number is: Five\n");
            break;
        case 6:
            printf("The name of the number is: Six\n");
            break;
        case 7:
            printf("The name of the number is: Seven\n");
            break;
        case 8:
            printf("The name of the number is: Eight\n");
            break;
        case 9:
            printf("The name of the number is: Nine\n");
            break;
        default:
            printf("The entered number (%d) is out of the supported range (0-9).\n", number);
            break;
    }
    // Validate the range
    if (number < 0 || number > 10000000) {
        printf("The entered number (%lld) is out of the supported range (0 - 10,000,000).\n", number);
        return 1; // Indicate an error
    }

    // Convert the number to words
    numberToWords(number, words);

    // Print the result
    printf("The name of the number is: %s\n", words);

    return 0; // Indicate successful execution
}
