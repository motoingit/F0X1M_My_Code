#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {1,2,3,4};

   //! Transferring the Ownership of memory to b        |      not Copy
    vector<int> b = std::move(a);

    cout << "Size of a: " << a.size() << endl; // usually 0
    cout << "Size of b: " << b.size() << endl; // 4
}
