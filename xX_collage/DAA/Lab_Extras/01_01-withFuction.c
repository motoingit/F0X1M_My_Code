#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int size, int key, int *counter){
    bool isFound = false;
    int i = 0;
    for (; i < size; i++) {
        if(arr[i] == key){
            isFound = true;
            break;
        }
    }
    *counter = i; //why not i+1 ( _-_ )
    return isFound;
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
        printf("Faild to Found !\n");
    }
    printf("Comparisons: ");
    printf("%d\n",counter);
return 0;}
