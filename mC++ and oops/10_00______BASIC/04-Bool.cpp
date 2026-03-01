#include<iostream>
using namespace std;

int main(){
    bool exp1 = true;
    bool exp2 = true;
    printf("%d ^ %d = %d",exp1,exp2,(exp1^exp2));

    bool exp3 = 1;
    bool exp4 = 0;
    cout << "This is Miracle "<<exp1 <<exp2 <<endl<<endl;

    
    cout << (exp1 && exp2) << endl;
    cout << (exp3 || exp4) << endl;
    cout << (!exp1) << endl;
}