// #Question: *Write a C program to Input a matrix and then Display the sum of rows INdividually*

//////////////////////////////  MY code >  ////////////////////////////////////////
#include <stdio.h>
void sum(int r, int c, int arr[r][c]);
int main(){
    int r, c;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);
	int arr[r][c];
    
    printf("Enter the elements of the matrix: ");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    }
//
	sum(r, c, arr);
return 0;}

void sum(int r, int c, int arr[r][c]){
    int sum0;
	for(int i = 0; i < r; i++){
	    sum0 = 0;
		for(int j = 0; j < c; j++){
			sum0 += arr[0][j];
		}
		printf("sum of row %d is %d\n", i+1, sum0);
	}
}


//INPUT : 1 2 3 4 5 6 7 8 9
//OUTPUT : sum of row 1 is 6
//         sum of row 2 is 15
//         sum of row 3 is 24

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