// Implement a C program to read 20 integers through command line arguments and store them into a file named Numbers.txt in the current working path. Then, read the file Numbers.txt and separate the numbers into two different files: odd.txt and even.txt as name suggest.


#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* fp0 = fopen("test.txt","r");
    FILE* fp1 = fopen("odd.txt","w");
    FILE* fp2 = fopen("even.txt","w");
    int even, odd, num;
    while(fscanf(fp0,"%d",&num) != EOF){
        if(num%2 == 0)
            fprintf(fp2,"%d ",num);
        else
            fprintf(fp1,"%d ",num);  
    }

    fclose(fp0);
    fclose(fp1);
    fclose(fp2);
return 0;}

/*
Sample :

File: Numbers.txt: 12 11 13 18 119 122 18 24 25 39 37 42 45 50 55 56 58 60 75 77

File: odd.txt: 11 13 119 25 39 37 45 55 77

File: even.txt: 12 18 122 18 24 42 50 56 58 60
*/