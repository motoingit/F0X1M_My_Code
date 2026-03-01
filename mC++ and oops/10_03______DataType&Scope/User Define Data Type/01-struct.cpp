#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks;
};  // or struct Student s1};     here we can define a variable directly

int main(){

    Student s1 = {"Mohit", 101, 92.5};   // string+int+float
    cout << s1.name << " - " << s1.rollNo << " - " << s1.marks;

return 0;}

/*

struct (Structure)
	• Groups different data types into a single logical unit.
	• By default, members are public.
    - Often used for lightweight data containers.
    
*/
