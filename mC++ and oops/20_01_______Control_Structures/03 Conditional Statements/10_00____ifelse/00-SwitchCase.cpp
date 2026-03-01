#include<iostream>
using namespace std;

int main(){
    char a;

    cout << "Enter the num1 : ";
    cin >> a;

    switch (a){
        case 'b' : 
        printf("this is B");
        break;

        case 'n' :



        printf("This is not CX");
        break;

        case 'p':


        cout << " ennter num1";

        // case 'n':  this gives error as it already exiwst
            cin >> a;


        default    :
            cout << " this is .";
            break;


    }

    return 0;
}