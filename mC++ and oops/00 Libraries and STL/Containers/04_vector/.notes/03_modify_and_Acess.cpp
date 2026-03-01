// modify

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1 = {1,2,3};
    
    cout << v1[2]; //! no bound check
    //? OR
    cout << v1.at(0); //* Safe access (throws exception) if not exist

    //* Modify
    v1[1] = 9;
    
    //* front or back ELEMENT acess
    cout << v1.front();
    cout << v1.back();


    v1.assign(0, 7); //* modify 0th idx with value 7

return 0;}
