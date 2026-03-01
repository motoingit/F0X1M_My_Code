#include <iostream>
using namespace std;

int main() {
    // Pointers and arrays
    int marks[] = {1,2,3,4};

    int* p = marks;  //marks is a Implicit Pointer
    cout<<*(p++)<<endl;
    cout<<*(++p)<<endl;

    cout<<"The value of *p is "<<*p<<endl;
    cout<<"The value of *(p+1) is "<<*(p+1)<<endl;
    cout<<"The value of *(p+2) is "<<*(p+2)<<endl; // outbounding
    cout<<"The value of *(p+3) is "<<*(p+3)<<endl; 
return 0;}