#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptra = &a;
    int **ptrb = &ptra;
    int ***ptrc = &ptrb;
    printf("%d %d %d\n\n",*ptrc,**ptrc,***ptrc);








// Toung Twister  (Not Recommended)    ⚠️⚠️⚠️⚠️
    int b = 100;

    int *ptr1 = &b;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;
    int ******ptr6 = &ptr5;
    int *******ptr7 = &ptr6;

    cout << "Value of a: " << a << endl;
    cout << "*ptr1: " << *ptr1 << endl;
    cout << "**ptr2: " << **ptr2 << endl;
    cout << "***ptr3: " << ***ptr3 << endl;
    cout << "****ptr4: " << ****ptr4 << endl;
    cout << "*****ptr5: " << *****ptr5 << endl;
    cout << "******ptr6: " << ******ptr6 << endl;
    cout << "*******ptr7: " << *******ptr7 << endl;

return 0;}