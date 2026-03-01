#include <stdio.h>
int main(){
    char str[] = "%d %c", arr[] = "GeeksQuiz";
    printf(str, 0[arr], 2[arr + 3]);          // arr[0] = 0[arr]      // 2[arr + 3] = arr[5]
    return 0;
}
