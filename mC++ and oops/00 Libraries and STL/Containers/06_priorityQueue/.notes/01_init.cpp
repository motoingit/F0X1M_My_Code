/*
std::priority_queue is a container adaptor built on top of a heap (usually a binary heap).
It always keeps the highest priority element at the top.
By default:🔥 It is a max-heap

                   //* typeofData  //*container     //*comparator
/// ! priority_queue  <int          ,vector<int>,   less<int>>      pq1; 
*/


#include <queue>
#include <iostream>
#include <deque>

using namespace std;

int main(){
    //* default (MAX-HEAP)
    priority_queue<int,vector<int>,less<int>> pq1;
    //? OR
    priority_queue<int> pq2;


    //* MIN-HEAP (by overiding the container and comparator)
    priority_queue<int, vector<int>, greater<int>> pqMin_Heap;

    //* with existing array
    vector<int> v = {10, 5, 20, 3};
    priority_queue<int> pq(v.begin(), v.end()); //todo: Heap built in O(n) time
    
    /* //? with custom comparator
    struct Compare {
        bool operator()(int a, int b) {
            return a > b;  // min-heap behavior
        }
    };
    priority_queue<int, vector<int>, Compare> pq;
    */


    /* //? with Using Lambda Comparator (Modern C++)
    auto cmp = [](int a, int b) {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    */

    //* By default it uses vector, but you can use deque:
    priority_queue<int, deque<int>> pq;

    //* copy constru
    priority_queue<int> pq1;
    priority_queue<int> pq2(pq1); //* Creates a copy of an existing heap.

    //* Move Initialization (Efficient Transfer)
    priority_queue<int> pq1;
    priority_queue<int> pq2(move(pq1)); //! Transfers ownership.

return 0;}


/*
| Type                | Syntax                                           | Use Case           |
| ------------------- | ------------------------------------------------ | ------------------ |
| Default             | `priority_queue<int>`                            | Max heap           |
| Min heap            | `priority_queue<int, vector<int>, greater<int>>` | Smallest first     |
| From range          | `priority_queue<int>(begin, end)`                | Bulk build         |
| Custom struct       | Custom comparator class                          | Complex ordering   |
| Lambda              | `decltype(cmp)`                                  | Clean modern way   |
| Different container | `deque`                                          | Rare edge case     |
| Copy                | `priority_queue(pq)`                             | Duplicate heap     |
| Move                | `priority_queue(move(pq))`                       | Efficient transfer |

*/
