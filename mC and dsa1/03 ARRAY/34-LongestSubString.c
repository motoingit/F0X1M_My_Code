//wap in c to find the largest substring amoung the super string
#include <stdio.h>
int noofwords(char *str){ //for counting the no of words
    int count = 0;
    for(int i = 0; *(str + i) != '\0'; i++){
        if(*(str + i) == ' ' && *(str + i) == '\0')
            count++;
    }
    count++;
    return count;
}

int main(){
    char str[50];
    printf("Enter the Super String :"); // im assuming that the words are of distint size;
    scanf(" %[^\n]",str);
    
    int len = noofwords(str);
    int arr[len][3];
    
    arr[0][0] = 0;
    
    int i = 0,j = 0;
    for(; i < len; i++){
        int lenx = 0; 
        arr[i][0] = j; 
        for(; str[j] != ' ' && str[j] != '\0'; j++){
            lenx++;
        }
        arr[i][2] = j - 1;
        arr[i][1] = lenx;
    }

    int temp = 1;
    int flag = 0;
    for(i = 0; i < len; i++){
        if(arr[i][1] < temp){
            flag = i;
            temp = arr[i][1];
        }
    }
    i = arr[flag][0];
    j = arr[flag][2];

    printf("The longest word is ");
    for(; i <= j; i++){
        printf("%c",str[i]);
    }
return 0;}