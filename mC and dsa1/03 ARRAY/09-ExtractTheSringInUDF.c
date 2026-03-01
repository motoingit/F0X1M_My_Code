// Ques: WAP in c to extract and print the Snippet form the string inputed  by user
//////////////////////////// MY //////////////////////////////
#include <stdio.h>
void extract(char[],char[],int,int);
int main(){
    char ms[1000],s[100]; // limition
    int i,j;

    printf("Enter the main String : "); //A good education transforms an individual into a good citizen
    scanf("%[^\n]s",ms);

    printf("Enter the range of Extration : ");
    scanf("%d %d",&i,&j);

    extract(ms,s,i,j);
    printf("Your extracted snippet is : [%s]",s); // how the changes inn udf affect the main
    
return 0;}

void extract(char ms[],char s[],int i,int j){ // 17 26
    int a,b; // why i and j is not working
    for(a = i,b = 0; a <= j; a++,b++)
        s[b] = ms[a];
    s[b] = '\0';
}
//////////////////////////// I-O //////////////////////////////
// Input:
// Output:




//////////////////////////// AI //////////////////////////////
