
/*
sorted by keys
*/

//! Insertion takes logn time 
//todo: But not in string (str.size()*logn)
#include <map>
#include <iostream>

using namespace std;

int main(){
    map<int, int> mp;


    mp[1] = 100; //* insert (1 with 100)
    mp[99];   //* insert (99key with 0val)

    //*returns  pair<iterator, bool>
    mp.insert({3, 300}); //* insert (3key with 300val)


    //! acessing an element takes logn
    for(auto &x : mp){   //* so this loop is talking nLogn time
        cout << x.first << " " << x.second << endl;
    }
    
return 0;}


