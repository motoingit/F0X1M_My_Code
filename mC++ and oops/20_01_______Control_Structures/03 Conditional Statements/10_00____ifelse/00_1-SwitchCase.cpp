#include<iostream>
using namespace std;
int main(){
    char a;

    cout << "Enter the num (1,2,3): ";
    cin >> a;

    switch (a){
        case '1' : 
        printf("\nthis is 1");
        break;

        case '2' : 
        printf("\nthis is 2");
        break;

        case '3' : 
        printf("\nthis is 3");
        break;

        default :
            cout << " this is Unknown";
            break;


    }

    return 0;
}