#include <stdio.h>
#include <stdlib.h> //lib for these funtion

// calloc() function allocates memory dynamically in heap*** whit values 0 by default
int main(){
    int n;
    printf("%dEnter number of  elements: ",sizeof(int));
    scanf("%d", &n);

    int* ptr = calloc(n , sizeof(int));    // here comma is $$
    if (ptr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    else{
        printf("Memory allocation succeeded\n");
        printf("Enter element :");
        for (int i = 0; i < n; i++){
            scanf("%d", (ptr + i));
        }

        printf("memory allocated :  ");
        for (int i = 0; i < n; i++){
            printf(" %p ", (ptr + i));
        }
        free(ptr); // Free the allocated memory
    }

return 0;}