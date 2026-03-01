/*
Write a Java program to print the elements of a given array in zigzag fashion. Given an array of n integers, rearrange the elements such that the first element is less than the second, the second is greater than the third, the third is less than the fourth, and so on. In general, the array should follow the pattern
a₁ < a₂ > a₃ < a₄ > a₅ < a₆ …

The program should read the value of n and the n array elements from the user and then display the modified array in zigzag order.

For example, if the input array is 4 3 7 8 6 2 1, the output should be 3 7 4 8 2 6 1. Similarly, for the input 1 4 3 2, the output should be 1 4 2 3.
*/


// import java.util.ArrayList;
import java.util.Scanner;

public class j05_PrintZigZag {
    static void zigzag(int[] arr, int n) { //! second method
        boolean less = true; // expected relation: < if true, > if false

        for (int i = 0; i < n - 1; i++) {
            if (less) {
                if (arr[i] > arr[i + 1]) {
                    // swap
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            } else {
                if (arr[i] < arr[i + 1]) {
                    // swap
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            less = !less; // flip expectation
        }
    }

    public static void printZigZag(int arr[], int n){
        int mid = n/2;

        int i1 ,i2;
        for (i1 = 0, i2  = mid ; i1 <= mid-1 && i2 <= n-1; i1++, i2++) {
            System.out.print(arr[i1]+" ");
            System.out.print(arr[i2]+" ");
        }
        if(n%2!=0 && i1 == mid){ //for odd n
            System.out.print(arr[i2]+" ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // ArrayList <Integer> arr = new ArrayList<>(); 
        int n = sc.nextInt(); //? n >= 3 
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt(); //? every n is distinct
        }

        printZigZag(arr, n);
    }
}
