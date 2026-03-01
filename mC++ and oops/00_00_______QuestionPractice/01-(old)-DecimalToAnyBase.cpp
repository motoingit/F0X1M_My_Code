
// decimal to any base conversion
// (x)10 to (z)y conversion

#include <iostream>
using namespace std;

void reverse(int* sum){

    int x = 0;
    int temp = *sum;
    while(temp > 0){
        int rem = temp%10;
        x = x*10 + rem;
        temp /= 10;
    }

    *sum = x;
}
int main() {
    //Inputing the Base and Number
    int base,num;
    cout << "ENter base and Num : ";
    cin >> base >> num;

    int temp = num, sum = 0;

    int rem;
    while(temp > 0 && temp >= base){

        int i = 1;
        while((temp / (base*i)) != 0){
            i++;
        }
        i--;

        rem = temp % (i * base);
        cout << "rem: " << rem << endl; // just to chek
        sum = sum*10 + rem;
        temp = i;
    }
    cout << "rem: " << rem << endl; // just to check
    sum = sum*10 + temp;

    reverse(&sum);
    cout << "The " << sum;
return 0;}