// Basic pattern with User row input as Square pattern

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){  //there is no problem even if you use i instead of j here (as scope forinner and ourter loop is  different)
            printf(" * ");           //but it is better to use j here as later on it become mess
        }
        printf("\n");
    }

    return 0;
}

// Output: Enter the number of rows: 5
//         *  *  *  *  *
//         *  *  *  *  *
//         *  *  *  *  *
//         *  *  *  *  *
//         *  *  *  *  *