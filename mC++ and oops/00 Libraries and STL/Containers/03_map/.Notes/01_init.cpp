/*
sorted by keys
*/
#include <map>
#include <iostream>

using namespace std;

int main(){
    
    std::map<int, int> mp;
    //? OR
    std::map<int, int, less<int>> mp;

    map<int, int, greater<int>> mp; //* Descending Order Map

return 0;}
