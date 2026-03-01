#include <stdio.h>
int main(){
    struct student{ char name; int roll_no; float percentage;}; //declare
    struct teacher{ char name1; int roll_no1; float percentage1;} monika, rikatho; //declare + Assign
    
    struct student navneet; //assign
    

    navneet.roll_no = 45;
    navneet.name = 'n';
    

    printf("%c",monika.name1);
    return 0;}