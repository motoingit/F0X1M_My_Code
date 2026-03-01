// Question 16 : Draw a flowchart & design a UDF that returns by swapping all the elements about the secondary diagonal of a matrix.
// Develop a C program to implement the function by accepting the rows and column in the main program. Display the swapped matrix 
// in the main program.  
////////////////////////////////////////////////////////////// MY //////////////////////////////////////////////////////////////////
#include <stdio.h>
int n;

void tx(int matrix[n][n]){
    int temp[n][n];
    int tem;
    for(int i = 0; i < n; i++){                            //right to left ghumaya
         for(int j = 0,q = n - 1; j < n; j++, q--){
             temp[i][q] = matrix[i][j];
        }
    }
    ///////////////////////////////////////////////////////////////////////
    for(int i = 0; i < n; i++){ //principle diagonal rotaion 
        for(int j = 0; j < n; j++){ // swaping without 3 vari
            if(i>j){
            tem = temp[j][i];
            temp[j][i] = temp[i][j];
            temp[i][j] = tem;
            }
        }
    }
    ////////////////////////////////////////////////////////////////
     for(int i = 0; i < n; i++){ // wapis se right to left
         for(int j = 0,q = n - 1; j < n; j++, q--){
             matrix[i][q] = temp[i][j];
        }
    }
}

int main(){
    printf("Enter the order of matrix :");
    scanf("%d",&n);
    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the [%d][%d] Element : ",i+1,j+1);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
    
    tx(matrix);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ",matrix[i][j]);
        }
        printf("\n");
    }
return 0;}


////////////////////////////////////////////////////////////// I-O ///////////////////////////////////////////////////////////////
/* 
Input: Enter the order of matrix : 3

    Enter the [1][1] Element : 1
    Enter the [1][2] Element : 2
    Enter the [1][3] Element : 3

    Enter the [2][1] Element : 4
    Enter the [2][2] Element : 5
    Enter the [2][3] Element : 6

    Enter the [3][1] Element : 7
    Enter the [3][2] Element : 8
    Enter the [3][3] Element : 9


Output: Restultant Matrix :
    
                9  6  3
                8  5  2
                7  4  1



*/
//////////////////////////// AI //////////////////////////////

