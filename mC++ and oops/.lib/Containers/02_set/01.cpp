// Question : 
#include <iostream>
#include <set>
using namespace std;

int main(){
    set <int> s;
    s.insert(10);
    s.insert(10); //duplicate ignore

    s.insert(20);
    //insert reutrns this >
    //? auto x = std::pair< std::set<int>::iterator, bool >
    //where
    // x.first -> iterator
    //x.second -> is present or not already


    s.erase(10); //by value
    s.erase(s.begin()); //by iterator

    // find return pointer adress if found other wise end()
    if (s.find(10) != s.end()) {
        // found
    }

    s.size();
    s.empty();

    for (auto x : s) { //traversing
        cout << x << " ";
    }


    //todo : advance thing
    auto it1 = s.lower_bound(10); // >= 10
    auto it2 = s.upper_bound(10); // > 10

    std::set<int, std::greater<int>> s;
                // OR
    struct cmp {
        bool operator()(int a, int b) const {
            return a > b;
        }
    };
    std::set<int, cmp> s;



return 0;}
