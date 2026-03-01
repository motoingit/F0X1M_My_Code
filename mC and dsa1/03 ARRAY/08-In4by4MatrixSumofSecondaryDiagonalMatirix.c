// #Question: *Write a C program to Sum and Display the sECONDARY digonal elements of 4by 4 matrix*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int arr[4][4] = {{1,2,3,0},{4,5,6,0},{7,8,9,0},{10,11,12,0}};
    int sum = 0;

    for(int i = 0,j = 3; i < 3 || j >= 0; i++,j--){
        sum += arr[i][j];
    }
    printf("The sum of the Secondary diagonal elements of the matrix is %d",sum);
    return 0;
}
//INPUT : null
//OUTPUT : The sum of the Secondary diagonal elements of the matrix is 24

////////////////////////     Completed           ////////////////////////////////////

//<

/* AI code >
///////////////////////////////////////////////////////////////////////////////////////
-------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////
<
*/