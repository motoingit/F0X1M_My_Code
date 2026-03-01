#include <stdio.h>
#include <stdlib.h>
int main(){
    int* ptr = (int*)calloc(5 , sizeof(int));  //   0000019A6C26FD10
    printf("%p\t",ptr); 
    ptr = realloc(ptr, 10 * sizeof(int));  // 0000019A6C26F710
    printf("%p",ptr); 
    free(ptr);
    ptr = NULL;
    return 0;
}