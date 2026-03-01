#include <stdio.h>
#include <time.h>

int main() {
    time_t startTime, currentTime;
    double elapsedSeconds;
    int loadingDuration = 10; // seconds

    printf("Loading started...\n");
    time(&startTime); // Get the starting time

    int dots = 0;
    while (1) {
        time(&currentTime); // Get current time
        elapsedSeconds = difftime(currentTime, startTime);

        if (elapsedSeconds >= loadingDuration) {
            break; // Exit loop after 10 seconds
        }
        

        // Simple animation
        printf(".");
        fflush(stdout);
        dots++;
        
        // You can add a small delay here if you want the dots to appear slower
        // For example, using a more complex delay or usleep if available
        // For this example, we'll let it spin fast or rely on a simple inner loop delay
        // Or, more practically, for a smooth loading bar, you'd update less frequently
        // than a tight loop allows.
        
        // A simple way to slow down dot printing a bit without usleep/Sleep
        for(long i=0; i < 50000000; ++i); // Crude delay, not recommended for precise timing

        if (dots % 10 == 0) { // Newline after 10 dots for neatness
            printf("\n");
        }
    }

    printf("\nLoading complete after approximately %.0f seconds!\n", elapsedSeconds);
    return 0;
}