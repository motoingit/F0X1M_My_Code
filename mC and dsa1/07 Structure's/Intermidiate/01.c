// understanding the behaviour of typedef struct in C
#include <stdio.h>
#include <string.h>

typedef struct date{ int day; int month; int year;}D;
typedef struct roomInfo{ 
    int roomNumber;
    char guestName[30]; 
    char guestMobileNumber[20]; 
    char guestAddress[100]; 
    float guestRent; 
    int roomType; 
    char guestPassword[10]; 
    char guestUsername[10]; 
    D d1;
}R;

int main(){
    R r1;
    r1.d1.day = 10;
    printf("%d\n", r1.d1.day);
    return 0;
}