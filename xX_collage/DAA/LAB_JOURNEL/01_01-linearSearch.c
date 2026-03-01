/*
Question: 01
    An array of non-negative integers
    A key element

    You must:
        Check whether the key is present in the array (using linear search)
        Count number of comparisons it, Does

    Time complexity must be O(n)
*/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T); // my test case

    while (T--) {
        printf("\n - - - \n");
        int n;
        scanf("%d", &n);   // size of array

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

        int idxFound = -1;
        int i = 0;
        for (; i < n; i++) {
            if (arr[i] == key) {
                idxFound = i + 1;
                break;
            }
        }

        if (idxFound != -1)
            printf("Present {%d} \n", idxFound); // we have to do (i+1)
        else
            printf("Not Present {%d}\n", idxFound); // base condition (aleady done i+1)
    }

return 0;}

/*

student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ gcc mohit_singh.c
student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ ./a.out
3 
8
34 35 65 31 25 89 64 30
89
Present {6}
5
977 354 244 546 355
244
Present {3}
6
23 64 13 67 43 56
63
Not Present {-1}

*/


/*
    ///* Best Case : O(1)
        Array: [10, 20, 30, 40]
        Key: 10

    ///? Avg Case : O(n)
        Array: [10, 20, 30, 40]
        Key: 30
        
    ///! worst Case : O(n)
        Array: [10, 20, 30, 40]
        Key: 50
*/


/* COMMAND //! input
5
0
1
-1
1
2
1 2
1
6
1 2 3 8 -1 -1
-1
10
1 100 1 200 1 20 30 30 1 0
0
*/

/* //! output

5 

 - - -
0
Array is Empty or Wrong !

 - - -
1
-1
1
Not Present {-1}

 - - -
2
1 2
1
Present {1}

 - - -
6
1 2 3 8 -1 -1
-1
Present {5}

 - - -
3
100 -4 -44
-4.5
Present {1}

*/
