#include <stdio.h>

float mean(int arr[], int size){
   int add = 0;
   for (int i = 0; i < size; i++) {
      add += arr[i];
   }
   return (float)add/size;  // ✅ cast to float for decimal result
}

int mode(int arr[], int size){
   // array should be sorted!
   int globalVin[2] = {1, arr[0]};
   int currVin[2]   = {1, arr[0]};

   for (int i = 1; i < size; i++) {
      if(currVin[1] == arr[i]){
         currVin[0]++;
      }else{
         currVin[0] = 1;
         currVin[1] = arr[i];
      }

      if(globalVin[0] < currVin[0]){
         globalVin[0] = currVin[0];
         globalVin[1] = currVin[1];
      }
   }
   return globalVin[1];
}

float median(int arr[], int size){
   int mid = size/2;

   if(size % 2 == 0){
      return (float)(arr[mid] + arr[mid-1]) / 2;  // ✅ cast to float
   }else{
      return arr[mid];
   }
}

int main() {
   int arr[] = {1, 1, 2, 2, 2, 3, 4, 5};  // sorted for mode to work
   int size = sizeof(arr)/sizeof(arr[0]);   // ✅ calculated in main

   printf("Mean   = %.2f\n", mean(arr, size));
   printf("Mode   = %d\n",   mode(arr, size));
   printf("Median = %.2f\n", median(arr, size));

   return 0;
}
