// (x)y to decimal conversion
/// this dont not work for base 16

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //Inputing the Base and Number
    int base,num;
    cout << "ENter base and Num : ";
    cin >> base >> num;

    int temp = num;

    int rem, sum = 0;
    int i = 0;
    while(temp > 0){
        rem = temp % 10;
        sum += rem * pow(base,i);
        temp /= 10;
        i++;
    }
    cout << "The " << sum;
return 0;}