// Ques: Wap in c to Extract the snippet from an array and display to the user
//////////////////////////// MY //////////////////////////////
#include <stdio.h>
int main(){
    char os[100],s[20];
    int i,j;

    printf("Enter the main String : "); //A good education transforms an individual into a good citizen
    scanf("%[^\n]s",os);

    for(i = 17,j = 0; i <= 26; i++,j++)
        s[j] = os[i];
    s[j] = '\0';

    printf("Your extracted snippet is : [%s]",s);
    
    return 0;
}
//////////////////////////// I-O //////////////////////////////
// Input:
// Output:




//////////////////////////// AI //////////////////////////////
