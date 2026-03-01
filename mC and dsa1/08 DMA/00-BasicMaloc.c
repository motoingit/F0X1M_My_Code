#include <stdio.h>
#include <stdlib.h> //lib for these funtion

// mallocate() function allocates memory dynamically in heap***
int main(){
    int n;
    printf("%dEnter number of  elements: ",sizeof(int));
    scanf("%d", &n);

    int* ptr = malloc(n * sizeof(int));    //(int*)malloc(n * sizeof(int)
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