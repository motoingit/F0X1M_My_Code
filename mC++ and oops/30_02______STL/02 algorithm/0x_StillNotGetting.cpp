#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    string s[] = {"abc", "bac", "dac"};
    int n = sizeof(s)/ sizeof(s[0]);

    sort(s, s+n);
    for(int i = 0 ; i < n; i++)
        cout << s[i] << endl;
}