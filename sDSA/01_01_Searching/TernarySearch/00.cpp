// Question : 
/*
    condition : sizeOdd =
*/
#include <iostream>
using namespace std;

int ternarySrch(int arr[], int st, int end, int key){
    int m1 = st + (end - st)/3;
    int m2 = m1*2;

    while(!(st <= end)){ //todo : not sure
        if(arr[m1] >= key){ //rang is st -> mid1
            if(arr[m1] == key){
                return m1;
            }
            end = m1-1;
        }else if(arr[m2] >= key){//rang is mid1+1 -> mid2
            if(arr[m2] == key){
                return m2;
            }
            st = m1+1;
            end = m2;
        }else{//rang is mid2+1 -> end
            st = m2+1;
        }
    }

    return -1; //here if not found
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/ sizeof(arr[0]);

    int st = 0, end = size-1, key = 2;
    int idx = ternarySrch(arr,st,end,key);

    cout << idx;
return 0;}
