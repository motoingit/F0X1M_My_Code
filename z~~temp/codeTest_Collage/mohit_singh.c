#include "moto.h"

int main(void) {
    lunixHeadingStartup();
    //
    int n;
    scanf("%d", &n);   // size of array

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
        printf("Present {%d}\n", idxFound); // we have to do (i+1)
    else
        printf("Not Present {%d}\n", idxFound); // base condition (aleady done i+1)
    //
    printLn();
    return 0;
}
