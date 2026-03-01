/*
Write a Java program to rearrange the elements of an array such that all negative numbers are moved to the beginning of the array and all positive numbers are moved to the end. The rearrangement should be done using a method that does not preserve the original order of elements.

The program should first declare an array and accept its elements from the user. While traversing the array, if a negative element is encountered, it should be swapped with the first positive element found earlier. This process should continue until all elements of the array have been processed. Finally, the program should display the rearranged array.

For example, if the input array is 1 -1 2 -2 3 -3, the output should be -1 -2 -3 1 3 2.

*/

import java.util.Scanner;

public class j06_sortingForSign {
    public static void swap (int arr[], int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void sortSign(int arr[], int n){
        int low = 0, i = 0, high = n-1;
        while (low < high && i <= high && i < n) {
            if( arr[i] > 0){
                swap(arr, i, high);
                high--;
            }else if(arr[i] < 0){
                swap(arr, i, low); // what if i and low is same
                low++;
                i++;
            }else{
                i++; //increment on 0 or -ve
            }
        }
    }
    public static void printArr(int []arr, int n){
        for (int x : arr) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        sortSign(arr, n);
        printArr(arr, n);

        sc.close();
    }
}
