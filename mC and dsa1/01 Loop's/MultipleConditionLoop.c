//series 09 18 27 36 45 54 63 72 81 90
#include <stdio.h>
int main(){
	int sum = 0;
    for(int i = 0,j = 9; i < 10 || j >= 0; i++,j--){
        printf("%d * %d",i,j);
        sum += i*j;
        printf(" = %d\n",i*j);
    }
    printf("\nsum of the series is %d\n",sum);
    return 0;
}