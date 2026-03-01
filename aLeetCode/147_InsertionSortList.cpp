// Question : 
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class my_Sorting{
    public:
        ListNode* insertionSort_forList(ListNode* head){
            ListNode *ptr = head;
            while(ptr != NULL){

                ptr = ptr->next;
            }
        }
};

/*
    -1 --> 5 --> 3 --> 4 --> 0
*/

int main(){
    
return 0;}
