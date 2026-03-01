#include <stdio.h>
int main(){
        if(rename("Mohit.txt","test.txt")== 0){
            printf("file reame sucessfullay");
        }
        else{
            printf("Rrror");
        }
return 0;}