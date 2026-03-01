// Question : 
#include <iostream>
using namespace std;

float divMoto(int n1, int n2){
    int res;

    try{
        if(n2 == 0)
            throw "Error: Null value is not Acceptable in denominator !";
        res = n1/n2;
    } catch(const char* e){
        cout << e;
        res = -1;
    } catch(...){
        cout << "Handling the Unxpected Error !" << endl; 
    }
    return res;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;

    float res = divMoto(n1,n2);
    cout << res ;

    cout << "Exiting Safly !" << endl;
return 0;}
