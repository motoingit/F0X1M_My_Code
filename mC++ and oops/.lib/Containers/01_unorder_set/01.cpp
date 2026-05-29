// Question : 
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set <int> us;

    us.insert(10);
    us.insert(20);

    if (us.find(10) != us.end()) {
        // found
    }

    us.erase(10);      // by value
    auto it = us.find(10);
    us.erase(it);      // by iterator


    //todo: if colision in hash happen
    // O(1) → O(n)


return 0;}
