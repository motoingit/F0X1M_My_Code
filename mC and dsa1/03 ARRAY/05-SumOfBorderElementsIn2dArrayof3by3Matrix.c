// #Question: *Write a C program to find the sum of periferal elements of a square matrix 3*3 by 2d Aray*

//////////////////////////////  MY code >  ////////////////////////////////////////

#include <stdio.h>
int main(){
	int a[4][4] = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};
	int sum = 0;
	int i = 0,j = 0;
	
	for(i = 0; i < 4; i++){
		if(i == 0 || i == (4-1)){
		    for(j  = 0; j < 4; j++)
		    	sum += a[i][j]; 
	    }
		else{
			for(int j  = 0; j < 4; j++){
				if(j == 0 || j == (4-1))
			    	sum += a[i][j]; 
			}
	    }
	}
	    //
	printf("The sum of pherical : %d",sum);
return 0;}

//INPUT : null
//OUTPUT : The sum of pherical : 30

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