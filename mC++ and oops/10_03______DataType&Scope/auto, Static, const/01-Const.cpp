#include <iostream>
using namespace std;
int main() {
    const int a = 10; // once declared then never gets changed
                        // read only block
    std::cout << a << std::endl;
    a = 11; // cant run;
return 0;}
