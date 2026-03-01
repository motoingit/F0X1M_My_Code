#include <iostream>  // For console input/output (like std::cout)
#include <queue>       // To get access to the std::queue container
using namespace std;   // To avoid writing std:: before cout, queue, etc.

int main() {
cout << endl;

    // 1. Declaration
    // This creates an empty queue that will hold integers.
    queue<int> q;

    // 2. Enqueue Operations
    // The push() method adds elements to the back of the queue.
    q.push(1); // Queue is now: [ 1 ]
    q.push(2); // Queue is now: [ 1, 2 ]
    q.push(3); // Queue is now: [ 1, 2, 3 ]

    // 3. Processing the Queue
    // The loop continues as long as the queue is not empty.
    while (!q.empty()) {
        // q.front() accesses the element at the front (1, then 2, then 3).
        cout << q.front() << " ";

        // q.pop() removes the element from the front.
        q.pop();
    }

cout << endl;
return 0;}
