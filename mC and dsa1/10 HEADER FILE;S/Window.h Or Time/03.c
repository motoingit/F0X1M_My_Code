#include <stdio.h>
#include <time.h>

int main() {
    time_t rawTime;
    struct tm *timeInfo;
    char buffer[80]; // Buffer to store the formatted time string

    // Get current raw time
    time(&rawTime); 

    // Convert to local time structure
    timeInfo = localtime(&rawTime);
    if (timeInfo == NULL) {
        perror("localtime failed");
        return 1;
    }

    // --- Using asctime (predefined format) ---
    printf("Current time (asctime): %s", asctime(timeInfo)); 
    // asctime includes a newline character at the end

    // --- Using ctime (simpler for time_t directly, also predefined format) ---
    printf("Current time (ctime):   %s", ctime(&rawTime));
    // ctime also includes a newline character at the end

    // --- Using strftime (custom format) ---
    // Format: YYYY-MM-DD HH:MM:SS
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    printf("Current time (strftime): %s\n", buffer);

    // Another custom format example
    strftime(buffer, sizeof(buffer), "Today is %A, %B %d, %Y. The time is %I:%M:%S %p.", timeInfo);
    printf("Current time (custom):   %s\n", buffer);
    
    // Accessing individual components:
    printf("Year: %d, Month: %d, Day: %d\n", 
           timeInfo->tm_year + 1900, // tm_year is years since 1900
           timeInfo->tm_mon + 1,    // tm_mon is 0-11
           timeInfo->tm_mday);      // tm_mday is 1-31

    return 0;
}