#include <stdio.h>
int main(){
    int status;
    status = remove("test.txt");    //     folder/file.txt for inside
    printf("%d\n",status);

        if(status== 0){
                printf("Deletesd");
        }
        else{
            printf("Rrror");
        }
return 0;}