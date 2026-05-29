// no of ways to create vector data 

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1; // default or empty vector
    
    vector <int> v2(1); // parametarized vector
    vector <int> v3(5,-1); // parametarized vector

    vector<int> v4 = {1,2,3,4}; // * complile time vector
    //? OR
    vector<int> v{1,2,3,4};

    //* Copies elements from another container.
    vector<int> v2(v1.begin(), v1.end());

    vector<int> v2(v1);//* copy construtor (Creates deep copy.)

    //? From Array Using Iterators
    int arr[] = {1,2,3};
    vector<int> v(arr, arr+3);

    //* 2D Vector Construction (3x3 matrix)
    vector<vector<int>> mat(3, vector<int>(3, 0));







    
                //! Out of Scope

    /* Transfers ownership.
    No deep copy. Very efficient. */
    vector<int> v2(std::move(v1));
    // v1 is empty (valid but unspecified)

    //Used in custom memory management scenarios.
    vector<int> v(allocator<int>());

return 0;}

/*         //* Summary

| Constructor Type | Example                     |
| ---------------- | --------------------------- |
| Default          | `vector<int> v;`            |
| Size only        | `vector<int> v(5);`         |
| Size + value     | `vector<int> v(5,10);`      |
| Initializer list | `vector<int> v{1,2,3};`     |
| Range            | `vector<int> v(a,b);`       |
| Copy             | `vector<int> v2(v1);`       |
| Move             | `vector<int> v2(move(v1));` |

*/
