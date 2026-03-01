// delete and clear

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1 = {1,2,3};
    
    v1.pop_back(); //* delete last indexed ele

    v1.clear(); //! to clear whole arr (size = 0)

    v1.erase(v1.begin() + 1); //* delete the element with pointer (1 idx element)
    v1.erase(v1.begin(), v1.begin()+2); //* delete the element(s) with pointer(s) in range (0 idx element to 2-1 idx)

return 0;}
