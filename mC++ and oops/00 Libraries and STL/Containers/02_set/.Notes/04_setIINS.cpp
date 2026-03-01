// Question : 

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    set <int> A = {1,2,3,4};
    set <int> B = {3,4,5,6};
    set <int> X;

    set_union(A.begin(), A.end(),
          B.begin(), B.end(),
          inserter(X, X.begin()));

    //? OR
    /*
    set<int> X = A;
    X.insert(B.begin(), B.end());
    */

    

return 0;}
