#include <stdio.h>
#include <stdlib.h> //for exit fx
void main(){
    FILE *fp = fp = fopen("01.bin","wb");
    int arr[] = {1,2,3,4,5};
    if(fp == NULL){
        printf("Error\n");
        exit(1);
    }
    else{
        fwrite(arr,sizeof(int),5,fp);
        fclose(fp);
    }

    fp = fopen("01.bin","rb");
    if(fp == NULL){
        printf("Error\n");
        exit(1);
    }
    else{
        int arr[5];
        fread(arr,sizeof(int),5,fp);
        
        for(int i = 0; i < 5; i++)
            printf("%d ",arr[i]);
        
        fclose(fp);
    }
}