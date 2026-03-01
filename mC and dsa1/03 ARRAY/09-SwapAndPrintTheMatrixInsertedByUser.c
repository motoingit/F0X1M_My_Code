// #Question: *Write a C program To make a 2d array by user and interchange its corner column*

//////////////////////////////  MY code >  ////////////////////////////////////////
#include <stdio.h>
int main(){
	int m,n;
	printf("Enter the column no :");
	scanf("%d",&n);
	printf("Enter the row no :");
	scanf("%d",&m);
	int eba[m][n];
///
	printf("\n\nEnter the elements of the matrix : ");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			scanf("%d",&eba[i][j]);
	}
///
	for(int i = 0; i < m; i++){
		eba[i][0] = eba[i][0] + eba[i][n-1];
		eba[i][n-1] = eba[i][0] - eba[i][n-1];
		eba[i][0] = eba[i][0] - eba[i][n-1];
	}
///	
	printf("\n\nThe new array is : \n\n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			printf("%d ",eba[i][j]);
		printf("\n");
	}
				
return 0;}

//INPUT : 1 2 3 4 5 6 7 8 9
//OUTPUT : 3 2 1
//         6 5 4
//         9 8 7

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