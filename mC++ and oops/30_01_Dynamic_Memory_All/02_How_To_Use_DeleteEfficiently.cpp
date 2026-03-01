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
            cout << "Consturction "<< endl;
        }
        ~XYZ(){ 
            cout << "Deleteing "<< endl;
        }

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
    XYZ o1;
    XYZ *o2 = new XYZ[10]; //calling the counstructor 10 times

    o2->get();
    (o2+5)->get();
    o2->get();

    ////////////intresting//////////////////////
    /*
        *(o2 + 5)  → object itself
        (o2 + 5)->get();   // ✅ works

        o2[9]   = *(o2 + 9) = object at index 9  
        (o2+5)    = pointer to object at index 5
        *(o2 + 5)  → pointer pointing to object at index 5   [object itself]
    */
    /////////////////////////////////////////////



    // o2.get();       its a pointer dude
    
    //only delete one object , 
    // delete o2;❌

    //delete all one by one✅
    delete [] o2;

cout << endl;
return 0;}