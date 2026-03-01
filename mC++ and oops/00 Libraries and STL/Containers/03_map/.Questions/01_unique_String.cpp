#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str[n];

    for(int i = 0; i < n; i++){
        cin >> str[i]; //without space
    }

    map <string, int, less<string>> myMap;

    for(auto &x : str){
        myMap[x] = myMap[x] + 1 ; 
    }

    for (auto &x : myMap) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
