#include <stdio.h>

void merge(int arrO[], int stIdx, int midIdx, int endIdx){
    int nL = midIdx - stIdx + 1;
    int nR = endIdx - (midIdx+1) + 1;

    int arrL[nL], arrR[nR];

    int x = stIdx, l =  stIdx, r = midIdx+1;
    while(l < nL){ // or till x <= midIdx
        arrL[l++] = arrO[x++];
    }
    while(r < nR){ // or till x <= midIdx
        arrR[r++] = arrO[x++]; //! many mistakes here in naming COnfustion
    }

    int l = 0, r = 0, x = stIdx; //* as x, l, r are all out of bound
    while (l < nL && r < nR){ //! i mistake here of <=
        if(arrR[r] < arrL[l]){
            arrO[x++] = arrR[r++];
        }else{ //if left is <= to right
            arrO[x++] = arrL[l++];
        }
    }
    while(l < nL){
        arrO[x++] = arrL[l++];
    }
    while(r < nR){
        arrO[x++] = arrR[r++];
    }
    
}

void mergeSort(int arr[], int st, int end){
    if(st == end)
        return;

    int mid = st + (end - st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,mid,end);
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1,6,3,8,0,3,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    if(size >= 2){
        int st = 0, end = size-1;
        printArr(arr,size);
        mergeSort(arr, st, end);
        printArr(arr,size);
    }else{
        printf("Wrong");
    }
return 0;}
