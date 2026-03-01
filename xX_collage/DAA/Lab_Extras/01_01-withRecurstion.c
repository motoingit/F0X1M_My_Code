#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int size, int key, int *counter){
    if( (*counter) == size){
        return false;
    }
    
    (*counter)++;
    if(key == arr[(*counter)-1]){
        return true;
    }

    return binarySearch(arr, size, key, counter);
}

int main() {
    int size;
    scanf("%d",&size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }

    int key;
    scanf("%d",&key);
    
    int counter = 0;
    if(binarySearch(arr, size, key, &counter)){ //call
        printf("Found it !\n");
    }else{
        printf("Failed to Found !\n");
    }
    printf("Comparisons: ");
    printf("%d\n",counter);
return 0;}
