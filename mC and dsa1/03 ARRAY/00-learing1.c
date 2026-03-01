#include <stdio.h>
#include <string.h>

int main() {
    char a[6] = {'M','o','h','i','t','\0'};
    char b[6] = {'M','o','h','i','t','\0'};
    int c = strlen(a);
    int d = sizeof(b);
    
    printf("%d ----- %d",c,d);
    return 0;
}
