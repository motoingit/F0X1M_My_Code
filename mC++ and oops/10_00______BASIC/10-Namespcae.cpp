// Question : 
#include <iostream>

namespace showNo{ // this is namespace created by me
    int num = 100;
    void printf(int num = num){
        std :: cout << num;
    }
}

int main() {
std :: cout << std :: endl; // this is default namespace

showNo :: printf(); // default argument
showNo :: num = 101;
showNo:: printf(showNo:: num); // using the showNo from my namespace and resolution prinf

std :: cout << std :: endl;
return 0;}