// size | capacity | isEmpty ?

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1 = {1,2,3};
    
    v1.size(); //* to return size of current vector

    v1.capacity(); //* to return capacity of current vector

    v1.empty(); //* to return isEmpty or not (bool)

    v1.resize(20); //* to reallocate the new memory for current data (dynamicaly)

return 0;}
