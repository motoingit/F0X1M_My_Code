#include <stdio.h>
#include <string.h>
// #include <conio.h>
int main(){
    FILE *fp;
    fp = fopen ("test.txt","w+");
    int len = getw(fp);
    printf("%d",len);
        
    fclose(fp);  
return 0;}
