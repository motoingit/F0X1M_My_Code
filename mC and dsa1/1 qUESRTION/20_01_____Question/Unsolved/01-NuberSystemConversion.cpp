#include <iostream>
using namespace std;
void base10t2(int num, int *sum);
int main(){ //only base 10 to 2 conversion
    int base,num;
    int sum = 0;
    cout << "Enter the base :" ;
    cin >> base;
    cout << "Enter the Number :";
    cin >> num;

    base10t2(num, &sum);
    cout << sum;
return 0;}

void base10t2(int num, int *sum){
    for(int i = 0; ; i++){
        if(num == 0)
            break;
        if(num%2 == 0)
            *sum = *sum *10 + 0;
        else
            *sum = *sum * 10 + 1;
        num = num/2;
    }
}