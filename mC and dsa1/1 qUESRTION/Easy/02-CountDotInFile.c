#include <stdio.h>
int main(){
    FILE *fp = fopen("File.txt","w");
    fprintf(fp,".My .Name .Mohit\n");
    fclose(fp);

    char ch;
    int count = 0;
    fp = fopen("File.txt","r");
    while(( ch = getc(fp) ) != EOF){
        if(ch == '.')
            count++;
    }
    printf("count %d",count);
    fclose(fp);

return 0;}