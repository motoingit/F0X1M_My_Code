#include <iostream>
#include <map>

using namespace std;

int main(){
  map<int, int> myMap;

  myMap.insert({1,100});
  myMap[4] = 400;

  for (auto &x : myMap){
    cout << "Key: " << x.first << "Val: " << x.second << endl;
  }

  auto pointerEle = myMap.find(2);
  if(pointerEle == myMap.end()){
    //! not found
  }else{
    //* found
  }
  
return 0;}