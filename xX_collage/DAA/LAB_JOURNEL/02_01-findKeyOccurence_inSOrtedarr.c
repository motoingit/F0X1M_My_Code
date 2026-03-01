/*
Question : 04
    Given a sorted array of positive integers containing a few duplicate elements, design and implement an algorithm to determine whether a given key element is present in the array. If the key is present, also find the number of copies of that key. The algorithm must run in O(log n) time complexity.
*/

#include <stdio.h>

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            printf("%d ",result);
            high = mid - 1;   // move left
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;    // move right
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
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

        int key;
        scanf("%d", &key);

        int first = firstOccurrence(arr, n, key);

        if (first == -1) {
            printf("Key not present\n");
        } else {
            int last = lastOccurrence(arr, n, key);
            int count = last - first + 1;
            printf("startIdx {%d} - times {%d}\n", first, count);
        }
    }
    return 0;
}

/*

student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ gcc mohit_singh.c
student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ ./a.out



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
