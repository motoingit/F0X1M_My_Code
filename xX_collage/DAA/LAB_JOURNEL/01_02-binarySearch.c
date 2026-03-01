/*
Question : 02
    Given an already sorted array of positive integers,
    design an algorithm and implement it using a program to:

    Check whether a given key is present
    Find the total number of comparisons

    Time Complexity: O(log n)
*/

#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);   // test n

    while (T--) {
        printf("\n - - - \n");
        int n;
        scanf("%d", &n);   // size arr

        if(n < 1){
            printf("Array is Empty or Wrong !\n");
            continue;
        }

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int key;
        scanf("%d", &key);

        int low = 0, high = n - 1;

        int idxFound = -1;
        int comparisons = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2; //this is stable mid
            comparisons++;

            if (arr[mid] == key) {
                idxFound = mid;
                break;

            }else if (arr[mid] < key) {
                low = mid + 1;

            }else if (arr[mid] > key) {
                high = mid - 1;
            }
        }

        if (idxFound != -1)
            printf("Present {%d}\n", comparisons);
        else
            printf("Not Present {%d}\n", comparisons);
    }
return 0;}


/*

student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ gcc mohit_singh.c
student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ ./a.out

3
8
10 20 30 40 50 60 70 80
50
Present 3
5
11 22 33 44 55
22
Present 3
6
5 15 25 35 45 55
100
Not Present 3

*/


/*
    ///* Best Case : O(1)
        Array: [10, 20, 30, 40, 50]
        Key: 30


    ///? Avg Case : log2​(n)
        Array: [10, 20, 30, 40]
        Key: 30
    /// as comparision is one only
        
    ///! worst Case : log2​(n)
        Array: [10, 20, 30, 40, 50, 60, 70, 80]
        Key: 90
    /// last element
*/
