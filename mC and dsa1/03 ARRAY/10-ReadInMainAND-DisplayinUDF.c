// #Question: *Write a C program to input the matrix by user and then display the matrix by use of udf*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
void display(int row,int col,int eba[row][col]);
int main(){
    int row,col;
    printf("Enter the number of rows and columns : ");
    scanf("%d %d",&row,&col);
	int eba[row][col];
	
    printf("Enter the elements of the matrix : ");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++)
			scanf("%d",&eba[i][j]);
	}
//
	display(row, col, eba);
return 0;}

void display(int row, int col, int eba[row][col]){
    printf("The matrix is :\n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++)
			printf("%d ", eba[i][j]);
		printf("\n");
	}
}
//INPUT : 3 3
//        1 2 3
//        4 5 6
//        7 8 9
//OUTPUT : The matrix is :
//         1 2 3
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