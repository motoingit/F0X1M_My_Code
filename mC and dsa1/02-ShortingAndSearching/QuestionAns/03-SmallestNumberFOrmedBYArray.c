//
#include <stdio.h>
int main(){
    int n = 11;
    int arr[] = {4,0,9,7,9,1,3,2,5,8,6};
    int i,j;
    printf("\nBefore test :");
    for(i = 0; i < n; i++){
        printf(" %d",arr[i]);
    }

    //
    for(i = 0; i < n - 1; i++){ //Minur changes for the Optimisation
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp =arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nAfter test :");
    for(i = 0; i < n; i++){
        printf(" %d",arr[i]);
    }

    i = 0;
    int sum = 0;
    while(i < n){
        sum = sum*10 + arr[i];
        i++;
    }
    printf("\n\nThe First Smallest Number is %d.",sum);

    for(j = n - 1; j >= 0; j--){
        if(arr[j] != arr[j - 1]){
            int temp =arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            break;
        }
    }

    i = 0;
    sum = 0;
    while(i < n){
        sum = sum*10 + arr[i];
        i++;
    }
    printf("\nThe second Smallest Number is %d.",sum);

return 0;}