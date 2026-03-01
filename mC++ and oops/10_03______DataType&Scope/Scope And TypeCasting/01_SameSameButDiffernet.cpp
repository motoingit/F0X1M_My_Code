#include <iostream>
using namespace std;

int main() {
    int num = 10; // this is diff
    while(true){
        float num = 20; //this num is diff


        if(::num == 20) // mai soch raha tha ki line 5 ka num hoga but 
            break;         // ye tho global ke liye hi use hota hai
    }


    return 0;
}
