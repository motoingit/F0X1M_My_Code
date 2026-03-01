//Push all the zeros to right and Mentaining the relative location of the no zero elements
#include <stdio.h>
int main(){
    int n = 10;
    int arr[10] = {0,1,0,0,4,0,6,-7,0,0};
    
    int i,j;
    printf("\nBefore :");
    for(i = 0; i < n; i++){
        printf(" %d",arr[i]);
    }

    int brr[n];
    for(i = 0,j = 0; i < n; i++){
        if(arr[i] != 0){
            brr[j] = arr[i];
            j++;
        }
    }
    for(i = j; i < n; i++){
        brr[i] = 0;
    }

    printf("\nAfter :");
    for(i = 0; i < n; i++){
        printf(" %d",brr[i]);
    }
}