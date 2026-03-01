#include <iostream>
using namespace std;

int main(){

    int apple,mango;
    cout<<"Enter the Number of apple : ";
    cin>> apple ;
    cout<<endl<<"Enter the number of mango : ";
    cin>>mango;

    //swap logiv
    apple = apple + mango;
    mango = apple - mango;
    apple = apple - mango;

    cout<<"After swapping The Apple and Mango are respectively :"<<apple <<"   "<<mango <<endl;
    
return 0;}