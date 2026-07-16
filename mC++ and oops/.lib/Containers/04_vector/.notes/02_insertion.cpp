// inserting methods

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1 = {1,2,3};
    
    v1.push_back(5); //* inserting element at last
    
    v1.insert(v1.begin(), 0); //* inserting at any pos
    //! sliding  element(s) and that pos element to right from that pos

    for (auto& i : v1) {
      cout << " " << i;
    }
return 0;}
