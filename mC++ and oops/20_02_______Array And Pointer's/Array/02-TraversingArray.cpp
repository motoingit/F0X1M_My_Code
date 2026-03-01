#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int marks[n] = {1,2,3};

    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    
            printf("\n\n");
            // OR

    int* ptr = marks; // main part
    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << " ";
    
            printf("\n\n");
            // OR

    // for each lop
    for (int i : marks)
        cout << i << " ";
    return 0;
}
