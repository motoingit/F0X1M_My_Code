#include <stdio.h>

int main() {
    printf("%d",printf("Hello")); ///so this means print return the no of character inside comma only
    // not even replacement of format specifier

    int a,b;
    // scanf("%d%d");



    // way 0
    printf("%d",scanf("%d%d",&a,&b)); // this means scanf returns the no of inputs it successfully have taken

    // way 1
    printf("%d",scanf("%d%d",&a)); //todo: Abnormal Termination 

    //way 2
    printf("%d",scanf("%d",&a, &b)); //todo: 2nd will get ignored
return 0;}
