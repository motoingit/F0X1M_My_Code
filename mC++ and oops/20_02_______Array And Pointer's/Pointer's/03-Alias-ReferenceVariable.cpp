#include<iostream> 
using namespace std;
int main(){
  

    // *************Reference Variables**************** 
    // Rohan Das----> Monty -----> Rohu ------> Dangerous Coder
    float x = 455;
    float & y = x; // Alias
    cout<<x<<endl;
    cout<<y<<endl;

    // both are same
    cout<<&x<<endl;
    cout<<&y<<endl;

    /*
            455
            455
            0x17e47ffe34
            0x17e47ffe34
    */

    return 0;
}
