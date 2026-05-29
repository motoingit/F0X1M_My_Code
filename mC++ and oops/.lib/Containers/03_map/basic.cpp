
/*
sorted by keys
///! Duplicate key is not gonna happen 

///! in string the lexocgraphical order 
*/
#include <map>
#include <iostream>

using namespace std;

int main(){
    map<int, int> mp;


    mp[1] = 100; //* insert (1 with 100)
    mp[99];   //* insert (99key with 0val)
    mp[99] = 123;   //todo: replace 0 with 123 in 99key (EXISTING)

    //*returns  pair<iterator, bool>
    mp.insert({3, 300}); //* insert (3key with 300val)



                        //* 🔷 Accessing Elements

    cout << mp[1];       // 100
    cout << mp.at(1);    // 100



                        //* 🔷 Searching
                        
    //!      find() returns iterator or end().
    auto it = mp.find(2);

    if (it != mp.end()) {
        cout << "Found : "<< it->first << " " << it->second;
    }else{
        cout << "Not Found";
    }

                        //* 4 Erasing
    // By key
    mp.erase(2);

    //By iterator
    mp.erase(it);

                        //* Traverstion
    for (auto &p : mp) {
        cout << p.first << " -> " << p.second << endl;
    }

return 0;}


