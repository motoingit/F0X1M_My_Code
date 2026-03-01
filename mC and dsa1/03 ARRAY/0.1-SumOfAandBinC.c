// #Question: *Write a C program to Initialise the array 1 2 and 3 and add and save of elements of 1 and 2 in 3 and print*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
    int a[3][3];
    int b[3][3];
    int c[3][3];
    printf("Enter the elements of a : ");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }
    
    printf("\n\n");///////////

    printf("Enter the elements of b : ");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&b[i][j]);
    }

    for(int i = 0; i < 3; i++){
        for(int j =0;j < 3;j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    
    printf("the elements of c : ");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",c[i][j]);
    }
    return 0;
}
//INPUT : 1 2 3 4 5 6 7 8 9 
 //Output : 1 2 3 4 5 6 7 8 9
//OUTPUT : 2 4 6 8 10 12 14 16 18

////////////////////////     Completed           ////////////////////////////////////

//<

/* AI code >
///////////////////////////////////////////////////////////////////////////////////////
'''''''''''''''''''''
///////////////////////////////////////////////////////////////////////////////////////////////
<
*/