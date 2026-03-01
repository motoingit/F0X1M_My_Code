#include <iostream>
int main(){
    int arr[100];
    for(int &i : arr){
        std::cin>>i;
    }
        
            printf("\n\n");
            // OR

    for(int i : arr)
        std::cout << i << " ";
    return 0;

}