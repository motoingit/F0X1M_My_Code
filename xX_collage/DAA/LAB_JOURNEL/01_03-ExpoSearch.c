/*
Question : 03
    Sorted array of positive integers
    Jump factor i *= 2

    Check whether key is present
    Count number of comparisons

    Complexity < O(n)
*/

#include <stdio.h>

int exponentialJumpSearch(int arr[], int size, int key){
  if (size < 1){
    printf("Array Empty or Wrong");
    return -1;
  }

  if (arr[0] == key)
    return 0;

  int i = 1;
  while (i < size && arr[i] < key) // selecting deterministic block
    i *= 2;
  

  // normalizing i
  if (i >= size)
    i = size - 1;

  //* now on segment apply any searchAlgo
  int low = i / 2, high = i;
  while (low <= high){
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
      return mid; //* found it
    else if (arr[mid] > key)
      high = mid - 1;
    else
      low = mid + 1;
    
  }

  return -1;
}


int linearSrc(int arr[], int key, int st, int end) {
    for (int i = st; i <= end; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int jumpSearch(int arr[], int size, int key, int factor) {
    int idx = 0;
    int prev = 0;

    // Jumping through blocks
    while (idx < size && arr[idx] < key) {
        prev = idx;
        idx += factor;
    }

    // If we jumped past the end, cap the end index at size - 1
    int searchEnd = (idx < size) ? idx : size - 1;

    // Perform linear search in the identified block [prev, searchEnd]
    return linearSrc(arr, key, prev, searchEnd);
}

int main()
{
  int T;
  scanf("%d", &T);

  while (T--)
  {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    int key;
    scanf("%d", &key);

    if (-1 != expoSrch(arr, n, key))
      printf("Present\n");
    else
      printf("Not Present\n");
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
