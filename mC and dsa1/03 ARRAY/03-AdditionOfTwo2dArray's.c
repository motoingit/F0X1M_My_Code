// #Question: *Write a C program to Add elements of 2 different 2d array*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int a[2][2] = {1,2,3,4};
    int b[2][2] = {2,4,6,8};
    int sum[2][2];
    
    for(int i = 0; i < 2; i++){
        for(int j =0;j < 2;j++)
            sum[i][j] = a[i][j]+ b[i][j];
    }
    //////
    for(int i = 0; i < 2; i++){
        for(int j =0;j < 2;j++)
            printf("%d ",sum[i][j]);
        printf("\n");
    }
return 0;
}
//INPUT : Null
//OUTPUT : 3 6
//         9 12 

////////////////////////     Completed           ////////////////////////////////////

//<

/* AI code >
///////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main() {
    // Declare and initialize two 2D arrays
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int arr2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int result[3][3];
    
    // Add corresponding elements of arr1 and arr2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    // Display the result array
    printf("Sum of the two 2D arrays is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
<
*/