// #Question: *Write a C program to double all the even elements in 2d array*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int vrr[2][2];
    //
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("Enter the Value for the vrr[%d][%d]",i+1,j+1);
            scanf("%d",&vrr[i][j]);
            if((vrr[i][j])%2 == 0)  //Great logic
                vrr[i][j] *= 2;
        }
        printf("\n");
    }
    //////
    for(int i = 0; i < 2; i++){
        for(int j =0;j < 2;j++)
            printf("%d ",vrr[i][j]);
        printf("\n");
    }
return 0;
}
//INPUT : 1 2 3 4
//OUTPUT : 1 4
//         3 8

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

    // Double all even elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] % 2 == 0) {
                arr[i][j] *= 2;
            }
        }
    }

    // Display the modified 2D array
    printf("The modified 2D array is:\n");
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