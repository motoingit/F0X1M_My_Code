#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int size, int key, int *counter){

    unsigned int left = 0, right = size-1;
    unsigned int mid;
    bool isFound = false;

    while (left <= right) {

        mid = left + (right - left)/2;
        (*counter)++;

        if(arr[mid] == key){
            isFound = true;
            break;
        }else if(arr[mid] > key){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return isFound;
}

int main() {
printf("\n");
    int T;
    printf("Enter nCase's :");
    scanf("%d",&T);

    while (T--) {
        int size;
        printf("Enter size :");
        scanf("%d",&size);
        
        printf("Enter Elements :");
        int arr[size];
        for (int i = 0; i < size; i++) {
            scanf("%d",&arr[i]);
        }

        int key;
        printf("Enter Key : ");
        scanf("%d",&key);
        
        int counter = 0;
        if(binarySearch(arr, size, key, &counter)){
            printf("Found it !\n");
        }else{
            printf("Faild to Found !\n");
        }
        printf("Comparisions : ");
        printf("%d",counter);
    }
    
printf("\n");
return 0;}
