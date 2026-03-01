// #Question: *Write a C program to find the sum and average of all the elements of 2d array*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int vrr[3][3];
    int sum = 0;
    //
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
            sum += vrr[i][j];
    }
    printf("%d",sum);
    return 0;
}
//INPUT : 1 2 3 4 5 6 7 8 9
//OUTPUT : 45

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

    int sum = 0;
    int count = 0;
    
    // Calculate sum and count elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
            count++;
        }
    }
    
    // Calculate average
    float average = (float)sum / count;
    
    // Display the 2D array
    printf("The 2D array is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // Move to the next row
    }
    
    // Display sum and average
    printf("\nSum of all elements: %d\n", sum);
    printf("Average of all elements: %.2f\n", average);

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
<
*/