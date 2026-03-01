// Question : 
#include <iostream>
#include <stdexcept>
using namespace std;

int main(){
    int ctrl;
    while(1){
        switch (ctrl){
            case 1:
                int n1, n2;
                cin >> n1 >> n2;
                try{
                    if(n2 == 0)
                        throw logic_error("Zero connot be in deno !");
                }catch(const logic_error &e){
                    cout << e.what();
                }
                break;
            /*
                | Exception          | When it’s used         |
                | ------------------ | ---------------------- |
                | `runtime_error`    | Runtime failures       |
                | `logic_error`      | Programming mistakes   |
                | `invalid_argument` | Bad function arguments |
                | `out_of_range`     | Index out of bounds    |

            */
            default:
                break;
        }
    }
return 0;}
