#include <iostream>
using namespace std;

int main() {
    int n = 10;
    // Diffrent ways to Declare or Initiate Array
    int marks[] = {1,2,3};
    int numbers[n];
    int moto[4] = {1,2,3,4};
    int elon[][3] = {1,2,3,
                     4,5,6,
                     7,8,9};
    int elon2[3][3] = {1,2,3,
                     4,5,6,
                     7,8,9};
    int arr[100];
    arr[0] = 1000000;
    // int elon[][] = {1,2,3,       //this gives error
    //                  4,5,6,
    //                  7,8,9};

    //to print array
    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;

    //OR

    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    
    return 0;
}
