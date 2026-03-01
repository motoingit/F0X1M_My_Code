#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    for(int i = a; i <= b; i++) {
        bool isPrime = true; // asuumeing
        
        // Handle special cases
        if(i <= 1) {
            isPrime = false;
        } else if(i == 2) {
            isPrime = true;  // 2 is prime
        } else if(i % 2 == 0) {
            isPrime = false; // Even numbers > 2 are not prime
        } else {
            // Check odd divisors up to sqrt(i)
            for(int j = 3; j <= sqrt(i); j += 2) {
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        
        if(isPrime)
            cout << i << " is Prime" << endl;
    }
    
    return 0;
}#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    for(int i = a; i <= b; i++) {
        bool isPrime = true; // asuumeing
        
        // Handle special cases
        if(i <= 1) {
            isPrime = false;
        } else if(i == 2) {
            isPrime = true;  // 2 is prime
        } else if(i % 2 == 0) {
            isPrime = false; // Even numbers > 2 are not prime
        } else {
            // Check odd divisors up to sqrt(i)
            for(int j = 3; j <= sqrt(i); j += 2) {
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        
        if(isPrime)
            cout << i << " is Prime" << endl;
    }
    
    return 0;
}