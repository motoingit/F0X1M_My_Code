// arry should be shorted before use this type of shorting.
#include <stdio.h>
int main (){
    int arr[] = {67,34,87,0,556,33,8,5,34,778,1,56,88};
    int x = 0;

    int last = 12, first = 99;
    while(first <= last){
        int mid = (first + last)/2;
        if( mid == x){
            printf("found on");
            break;
        }
        if(x > mid)
         first = mid + 1;
        else
            last = mid -1;
    }
    return 0;}