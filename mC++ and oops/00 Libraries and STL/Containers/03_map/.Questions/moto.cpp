// Question : 

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, string> myMap;

    myMap[20] = "Mohit";
    myMap[30] = "Mo32";
    myMap[100] = "Mo234hit";
    myMap.insert({90, "Rohit"});

    map<int, string> :: iterator it;
    for(it=myMap.begin(); it != myMap.end(); it++){ //todo: In-order traversal
        cout << (it->first) << " | " << (*it).second << endl;

        //! first Dereference pointer then acess memeber
        // (it->first)   ==    // (*it).first

        //! ERROR : You cannot dereference an int unless ------ map<int*, string>
        //      *(it->first)
        //      *(it)->first

        //! Same thing (same error as above)
        //*     *(it)->first   == *it->first
        
    }

                        //* FIND *//

    auto it = myMap.find(20); //* return iterator or end()
    if(it != myMap.end()){
        cout << "Found : " << (it->first) << " | " << (*it).second << endl;
    }else{
        cout << "not Found";
    }

                        //* DEELTE *//

    //! erase can give error if key not exist
    myMap.erase(20); //* by key
    myMap.erase(myMap.find(100)); //* by iterator

    myMap.clear();
 
return 0;}
