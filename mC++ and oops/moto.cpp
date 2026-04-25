/* Question : String Matching 01
*/

#include <iostream>
#include <string>
#include <format>

using namespace std;

//only find first occurence
void findPattern(string str, string pattern){
    int pIdx = 0, sIdx = 0;
    while (sIdx < str.size()) {
        if(str[sIdx] == pattern[pIdx]){
            pIdx++;
            if(pIdx == pattern.size()){
                printf("Found at %d to %d", sIdx-pattern.size(), sIdx-1);
                return;
            }
        }else{
            pIdx = 0;
        }
        sIdx++;
    }
    
    printf("Not Found");
}

int main(){
    string str = "hello.mello.hollahito.hellno";
    findPattern(str, "hellno");

    cout << "Terminated Sucessfully";
return 0;}
