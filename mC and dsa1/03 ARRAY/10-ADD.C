#include <stdio.h>
int rem(int[]);
int main(){
    int r;
    int arr[] = {1,2,3,4,5,6,7,8,9,0}; 
    printf("Reminder is %d",rem(arr));
return 0;}
//////////////////////////
int rem(int arr[10]){
    int i,r;
    int sume = 0,sumo = 0;
    for(i = 0; i < 10; i++){
        if(arr[i]%2 == 0)
        sume += arr[i];
        else
        sumo += arr[i];
}
r = sume % sumo;
return r;}