#include <stdio.h>
#include <string.h>
int isprime(int*,int*);
int main(){
    int num, flag = 0;

    printf("enter the num :");
    scanf("%d",&num);
    int *x = &num;
    int *y = &flag;
    flag = isprime(x,y);

    if(flag == 0)
        printf("Is prime !");
    else
        printf("Not prime !!!");
return 0;}
int isprime(int *x,int *y){
    for(int i = 2; i <= *x/2; i++){
        if( *x % i == 0){
            *y = 1;
            return *y;
        }
        else    
            return 0;
    }
}