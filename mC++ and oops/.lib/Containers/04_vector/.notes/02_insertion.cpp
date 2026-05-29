// inserting methods

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1 = {1,2,3};
    
    v1.push_back(5); //* inserting element at last
    
    v1.insert(v1.begin(), 0); //* inserting at any pos
    //! sliding the right element(s) to right from that pos

return 0;}
