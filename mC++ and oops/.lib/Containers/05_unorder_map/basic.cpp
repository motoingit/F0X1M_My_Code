#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    //! key value pair
    unordered_map<string, int> um1;
    unordered_map<int, int> um2 = {
        {1,1230},
        {6,1230},
        {2,1230},
    };
    unordered_map<int, int> um3(um2); //but um2 should have same structure
    
    um1["Alice"] = 25; //todo:   alice is key , and 25 is value
    um1["Bob"] = 30;

    um2.insert({6, 200});
    um2.emplace(7, 300); //same as inseert



    // Access value by key
    cout << "Alice's age: " << um1["Alice"] << endl;

    // Check existence
    auto it = um1.find("Charlie");
    if ( it == um1.end())
        cout << "Charlie not found\n";

    

    cout << um2[5]; //! create value if not present
    cout << um2.at(5);   // throws error if not present

    um2.erase(5);
    um2.clear();

    um2[5] += 1;

    for (auto it : um2) {
        cout << endl;
        cout << it.first << " " << it.second << endl;
    }


    return 0;
}
