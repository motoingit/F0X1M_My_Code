// Question : 
#include <iostream>
using namespace std;
class XYZ{
    public:
        int data;
    friend XYZ operator+(XYZ& lhs, XYZ& rhs){
        XYZ temp;
        temp.data = lhs.data + rhs.data;
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