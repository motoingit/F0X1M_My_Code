// Question : 
#include <iostream>
using namespace std;

class XYZ{
    public:
        //data member
        int data;

        // constuctor
        XYZ(){}
        XYZ(int data){
            this->data = data;
        }
        ~XYZ(){}

        //fuction
        void set(int data){
            this->data = data;
        }
        void get(){
            cout << data << endl;
        }
};

int main() {
cout << endl;
    XYZ o1(10);
    XYZ *o2 = new XYZ(20);
    
    o1.get();
    o2->get();
    // o2.get();       its a pointer dude

cout << endl;
return 0;}