/*
Question : 03
    Sorted array of positive integers
    Jump size (m = 2) // in our course

    Check whether key is present
    Count number of comparisons

    Complexity < O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int exponentialSearch(const vector<int>& arr, int key) {
    int n = arr.size();

    if (arr[0] == key)
        return 0;

    int i = 1;

    while (i < n && arr[i] <= key)
        i *= 2;

    return binarySearch(arr, i / 2, min(i, n - 1), key);
}

int main() {

    vector<int> arr = {
        3, 7, 12, 15, 19, 24, 28, 31, 35, 39,
        42, 47, 51, 56, 60, 64, 69, 73, 78, 82,
        87, 91, 96, 101, 107, 112, 118, 123, 129, 135
    };

    vector<int> testKeys = {3, 56, 135, 50, 1};

    for (int key : testKeys) {
        int result = exponentialSearch(arr, key);

        if (result != -1)
            cout << "Key " << key << " found at index " << result << endl;
        else
            cout << "Key " << key << " not present" << endl;
    }

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
