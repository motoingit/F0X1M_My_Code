// Inserting in Vector;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // initiating with manual size
    vector <int> xyz(10);

    //inputing
    for(int i = 0; i < 10; i++){
        cin >> xyz[i];
    }

    //output
    for(int i = 0; i < 10; i++){
        cout << xyz[i] << " ";
    }

    cout <<  endl;
    cout << xyz.size() <<  endl; // 10
    cout << xyz.capacity() << endl; // compiler dependent

    xyz.resize(20); // size to 20 and copy data

    cout << xyz.size() <<  endl;  //20
    cout << xyz.capacity() << endl; // cand determinded

    
return 0;}