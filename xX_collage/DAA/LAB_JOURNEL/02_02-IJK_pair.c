/*
Question : 05
    You are given a sorted array of positive integers.
    You must find three indices i, j, k such that:

        arr[i]+arr[j]=arr[k]

        If any such triple exists, print the indices.
        If no such triple exists, print: not fonund any
*/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        printf("\n= = = = =\n");
        int n;
        scanf("%d", &n);

        if(n < 1 ){
            printf("Array Empty or Wrong");
            return -1;
        }

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int found = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                int sum = arr[i] + arr[j];

                if (sum == arr[k]) {
                    printf("[%d, %d, %d]\n", i + 1, j + 1, k + 1);
                    found++;
                    i++;
                } else if (sum < arr[k]) {
                    i++;
                } else if (sum > arr[k]) {
                    j--;
                }
            }
        }

        if (!found) {
            printf("No sequence found.\n");
        }else{
            printf("%d in Total.\n", found);
        }
    }

    return 0;
}


/*

student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ gcc mohit_singh.c
student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ ./a.out
3
5
1 2 3 4 7
3, 4, 5
1, 3, 4
1, 2, 3
10
23 45 67 88 99 100 455 555 676 898    
6, 7, 8
7
3 8 9 10 22 33 55
5, 6, 7
*/


/*
    ///* Best Case : O(n2)
        Array: [10, 20, 30, 40, 50]
        Key: 30


    ///? Avg Case : log2​(n2)
        Array: [10, 20, 30, 40]
        Key: 30
    /// as comparision is one only
        
    ///! worst Case : log2​(n2)
        Array: [10, 20, 30, 40, 50, 60, 70, 80]
        Key: 90
    /// last element
*/
