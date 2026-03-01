#include <stdio.h>
int main(){
    int arr[] = {1,2,3,4,5};
    int i;
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    arr[2] = 10; // Replace the value at index 2 with 10

     for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}