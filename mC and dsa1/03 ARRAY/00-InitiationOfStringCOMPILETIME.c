//wap in c to initialise string in comple time and print the string.
#include <stdio.h>
int main(){
    char a[6] = {'M','o','h','i','t','\0'}; //method 1
	char b[] = "Mohit";                     //method 2
	char c[] = {'R','o','h','i','t','\0'};  //method 3
    printf("String a : %s\n",a);
    printf("String b : %s\n",b);
    printf("String c : %s\n",c);
return 0;
}

