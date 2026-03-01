// #Question: *Write a C program to Sum and Display the digonal elements of 4by 4 matrix*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int arr[4][4] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int sum = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0;j < 3;j++){
            if(i==j)
                sum += arr[i][j];
        }
    }
    printf("The sum of the diagonal elements of the matrix is %d",sum);
    return 0;
}
//INPUT : 1 2 3 4 5 6 7 8 9
//OUTPUT : The sum of the diagonal elements of the matrix is 15

////////////////////////     Completed           ////////////////////////////////////

//<

/* AI code >
///////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main() {
    // Declare and initialize a 2D array
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display the 2D array
    printf("The 2D array is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
<
*/