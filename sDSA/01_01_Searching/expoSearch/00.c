/*
Question : 03
    Sorted array of positive integers
    Jump size (m = 2) // in our course

    Check whether key is present
    Count number of comparisons

    Complexity < O(n)
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    scanf("%d", &key);

    int idxFound = -1;;

    // Step 0: check first element
    if (arr[0] == key) {
        printf("Present\n");
        return 0;
    }

    // Step 1: exponential range finding
    int low = 1, high = 2;

    while (high < n && arr[high] < key) {
        low = high;
        high = high * 2;
    }

    if (high >= n)
        high = n - 1;

    // Step 2: binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            idxFound = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (idxFound != -1) //* this is idx of key
        printf("Present\n");
    else
        printf("Not Present \n");

    return 0;
}



/*

student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ gcc mohit_singh.c
student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ ./a.out

3
8   
10 20 30 40 50 60 70 80
70
Present 4
5
15 25 35 45 55
15
Present 1
6
5 10 15 20 25 30
100
Not Present 3

*/


/*
    ///* Best Case : O(1)
        Array: [10, 20, 30, 40]
        Key: 10

    ///? Avg Case : O(n)
        Array: [10, 20, 30, 40]
        Key: 30
        
    ///! worst Case : O(n/m + m)
        Array: [10, 20, 30, 40]
        Key: 50
    ///When?  {Key is not present}    {Or in last block}
*/
