// Question : 
#include <iostream>
using namespace std;

int main() {
cout << endl;

    int num1, num2, res;
    cin >> num1 >> num2;
    try{
        if(num2 == 0)
            throw "Error: Null value is not Acceptable !";
        res = num1/num2;
    } catch(const char* e){
        cout << e;
    } catch(...){
        //todo:  if you mistakely write string& in above catch the input (10 0) will make to fall here LOL
        cout << "Handling the Unxpected Error !" << endl; 
    }
cout << endl;
return 0;}
