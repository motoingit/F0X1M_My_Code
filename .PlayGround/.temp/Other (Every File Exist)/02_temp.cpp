#include <iostream>
using namespace std;

class XYZ{
    int x;
    public:
        XYZ(){}
        XYZ(int x){
            this->x = x; //this this is the implicit pointer
        }
        void operator -(){
            this->x = -x;
        }
        void printX(){
            cout << x;
        }
};

int main(){
    XYZ obj1(20);
    obj1.printX();
    -obj1;
    obj1.printX();
return 0;}
