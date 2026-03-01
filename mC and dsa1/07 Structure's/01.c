//Wap in c to input the detals of students using sturctures
#include <stdio.h>
struct student{ char name[20]; int roll_no; char section;};
int main(){
    struct student enrollno[5];
    for(int i = 0; i < 5; i++){
    printf("Enter the %d Name :",i+1);
    scanf(" %s",enrollno[i].name);
    printf("Enter roll no: ");
    scanf(" %d",&enrollno[i].roll_no);
    printf("Enter section :");
    scanf(" %c",&enrollno[i].section);

    printf("\n\n");
    }

return 0;}