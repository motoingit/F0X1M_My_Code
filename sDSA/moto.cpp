/* Question : Naive String Matching
*/

#include <iostream>
#include <vector>

using namespace std;

void fun(string &text, string &ptrn){
    for(int i = 0; i <= text.size() - ptrn.size(); i++){
        int j = 0;
        while(j < ptrn.size() && text[i + j] == ptrn[j]){
            j++;
        }
        if(j == ptrn.size()){
            cout << "Found at " << i << endl;
            return;
        }
    }
    cout << "Not found";
}

int main(){
   string text = "abedbced";
   string ptrn = "ced";

   fun(text, ptrn);

return 0;}
