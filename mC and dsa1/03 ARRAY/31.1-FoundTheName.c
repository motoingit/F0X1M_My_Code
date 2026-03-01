//Wap in c to find the  inputed name in the 2d array;
#include <stdio.h>
int main(){
    char arr[5][10] ={"MOHIT","NAVNEET","ALOK","SIDDHARTH","SHAGUN"};
    int i,j;
    // for(i = 0; i < 5; i++)
    //     printf("%d = %s\n",i+1,arr[i]);
    char orr[10];
    printf("Enter a name to find : ");
    scanf("%s",orr);

    int flag = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; orr[j] != '\0'; j++){
                if(arr[i][j] != orr[j] && arr[i][j + 1] != orr[j + 1]){
                    flag = 0;
                    break;
                }
                else{
                    flag++;
                }
        }
        if(flag > 0){
            printf("Found it !");
            return 0;
        }
    }
    printf("Not found it !");

return 0;}