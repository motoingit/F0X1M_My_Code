#include <stdio.h>
#include <limits.h>
void swap(int*,int*);
int main(){
    int arr[] = {5,4,3,2,1,0};
    int n = 6;

    int i,j;
    printf("\nBefore Sorting : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

//selection sort
    
    for(i = 1; i < n; i++){ 
        j = i;
        while(j >= 1 && arr[j] < arr[j-1]){
            swap(&arr[j-1], &arr[j]);
            j--;
        }
    }

    printf("\nAfter : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

return 0;}
void swap(int* x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}