// #Question: *Write a C program to declare and initialize a 2D array and display the same*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};  //method 1
    int brr[3][3] = {2,6,7,8,9,4,6,7,0}; //method 2
    int vrr[3][3]; //method 3

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter the Value for the vrr[%d][%d]",i+1,j+1);
            scanf("%d",&vrr[i][j]);
        }
        printf("\n");
    }
    //////
    for(int i = 0; i < 3; i++){
        for(int j =0;j < 3;j++)
            printf("%d",vrr[i][j]);
        printf("\n");
    }
    return 0;
}
//INPUT : 1 2 3 4 5 6 7 8 9
//OUTPUT : 1 2 3
//         4 5 6
//         7 8 9

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