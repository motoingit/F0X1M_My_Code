//Wap in c to concratition two different string  and then display
#include <stdio.h>
#include <string.h>
int main(){
    int i,j,x,y;
    char a[100], b[100];
    printf("Enter the string 1 : "); //graphic/0  // 
    gets(a);
    printf("Enter the string 2 : "); //era/0  //
    gets(b);

    x = strlen(a),y = strlen(b);
    for(i = 0,j = 0;b[j] != '\0' ; i++, j++)
        a[i+x] = b[j];
    a[i] = '\0';

    printf("The Resultant String is : {%s}",a);

return 0;}