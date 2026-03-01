//  write a code in c to modify all the vowels in upercase present in a file and display the resultant to the user.
#include <stdio.h>
int main(){
    FILE* fp1 = fopen("file.txt", "r+");
    if (fp1 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char ch;

    printf("Your Out put is : ");
    while((ch = fgetc(fp1)) != EOF){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            ch -= 32;
            fseek(fp1, -1, SEEK_CUR);
            fputc(ch, fp1);
            fseek(fp1, -1, SEEK_CUR);
        }
        printf("%c",ch);
    }

return 0;}