#include <stdio.h>
int main(){
    int n = 10;
    int arr[] = {4,0,7,9,1,3,2,5,8,6};
    int i,j;
    printf("\nBefore test :");
    for(i = 0; i < n; i++){
        printf(" %d",arr[i]);
    }

    int k;
    printf("\nEnter kth term : ");
    scanf("%d",&k);

    //
    for(i = 0; i < k; i++){ //Minur changes for the Optimisation
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j + 1]){
                int temp =arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf(" \n%d Is that required element.",arr[n-k]);  //k+x = n          //index

    printf("\nAfter test :");
    for(i = 0; i < n; i++){
        printf(" %d",arr[i]);
    }
return 0;}