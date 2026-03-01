// Question : 
#include <iostream>
using namespace std;
class XYZ{
    public:
        int data;
    XYZ operator+(XYZ& rhs){ //do i need friend here
        XYZ temp;
        temp.data = data + rhs.data;
        return temp;
    }

    XYZ(){}

};

int main() {
cout << endl;
    XYZ o1, o2, o3;

    o3 = o1 + o2;
    
cout << endl;
return 0;}