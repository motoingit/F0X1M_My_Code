#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout << "Enter the Num1 and Num2 : ";
    // cin >> a >> b;
    scanf("%d %d", &a, &b);
    if(b == 0){
        printf("Num2 should not be 0.");
    }
    else{
        a = a/b;
        cout << a << " is your Division.";
    }
    return 0;
}