
/*
    Given an array of nonnegative integers, design an algorithm and a program to count the number
    of pairs of integers such that their difference is equal to a given key (K).
*/

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        if(n < 1){
            printf("Error ");
            return -1;
        }

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int key;
        scanf("%d",&key);

        //? method 1 (n2)
        //! n2 T.C
        // for(int i = 0; i <= n-2; i++){
        //     for(int j = i+1; j <= n-1; j++){
        //         if(key == arr[i] - arr[j] || key == arr[j] - arr[i]){
        //             // printf("%d %d\n",i,j);
        //             count++;
        //         }
        //     }
        // }

        //? method 2
        //* srting
        mergeSort(arr, 0, n - 1);
        int i = 0, j = 1;
        int count = 0;

        while (j < n) {
            int diff = arr[j] - arr[i];

            if (diff == key) {
                count++;
                i++;
                j++;
            } else if (diff < key) {
                j++;
            } else {
                i++;
                if (i == j)
                    j++;
            }
        }

        if(count == 0){
            printf("No Pair Found\n");
        }else {
            printf("%d Pairs Found\n", count);
        }
    }
return 0;}
