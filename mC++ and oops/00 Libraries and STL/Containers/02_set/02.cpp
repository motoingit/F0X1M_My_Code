// Question : 
#include <iostream>
#include <set>
using namespace std;

int main(){
    set <string> strSet = {"Rohit", "Kanta", "Hiruzen"};
    strSet.insert("Mohit");
    strSet.insert("10");
    
    // cout << strSet.count("Hiruzen");

    // ! // if find()
    // if (strSet.count("10")) {
    //     cout << "Exists";
    // }

    //? second que
    // set<int> s = {2,5,8,10};
    // for(auto x : s){
    //     if(x >= 6){
    //         printf("Exist");
    //         cout << x;
    //     }
    // }

    set <int> s2 ;
    s2.insert(20);
    cout << *s2.end();
return 0;}

//ques : what is the undefined behavior
//? ans : anything which doesnt handled with the devloper or out of bonds 
