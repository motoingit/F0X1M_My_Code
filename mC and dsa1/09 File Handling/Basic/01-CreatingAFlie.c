#include <stdio.h>
int main(){
    FILE* ptr = fopen("create.txt","a");

    if(ptr == NULL){
        printf("Error");
    }
    else{
        printf("Sucess");
        fclose(ptr);  
    }
    
return 0;}