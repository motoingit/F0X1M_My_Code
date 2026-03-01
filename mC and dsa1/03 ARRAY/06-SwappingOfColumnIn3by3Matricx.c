// #Question: *Write a C program to swap two column square matrix 3*3 by 2d Aray*
//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    for( int i = 0; i < 3; i++ ){ // no of rows
        for( int j = 0; j < 3; j++ ){ // no of column              //if a = 2 and b = 3 then swapping
            arr[i][0] = arr[i][0] + arr[i][2];                               // a = a + b
            arr[i][2] = arr[i][0] - arr[i][2];                               // b = a - b
            arr[i][0] = arr[i][0] - arr[i][2];                               // a = a - b
        }
    }
///////////////////////////////////////////////////////////////////////   
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++ )
            printf("%d ",arr[i][j]);
        printf("\n");
    }   
///////////////////////////////////////////////////        
return 0;}
//INPUT : null
//OUTPUT : 3 2 1
//         6 5 4
//         9 8 7

/////////////////////////////  Completed    ////////////////////////////////////

//<
/* AI code >
///////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
int main(){
    int arr[3][3], i, j, col1, col2, temp;

    // Taking input for the 3x3 matrix
    printf("Enter 9 elements for the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Taking input for the two columns to swap
    printf("Enter the two column indices (0-2) to swap: ");
    scanf("%d %d", &col1, &col2);

    // Validating column indices
    if (col1 < 0 || col1 > 2 || col2 < 0 || col2 > 2) {
        printf("Invalid column indices! Please enter values between 0 and 2.\n");
        return 1; // Exit the program with an error code
    }

    // Swapping the columns
    for (i = 0; i < 3; i++) {
        temp = arr[i][col1];
        arr[i][col1] = arr[i][col2];
        arr[i][col2] = temp;
    }

    // Displaying the modified matrix
    printf("\nMatrix after swapping column %d and column %d:\n", col1, col2);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
<
*/