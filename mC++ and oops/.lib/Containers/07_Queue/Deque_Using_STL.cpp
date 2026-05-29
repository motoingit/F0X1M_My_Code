#include <iostream> // For std::cout
#include <deque>    // To get access to the std::deque container
using namespace std;

int main() {
    // 1. Declaration: Create an empty deque of integers.
    deque<int> dq;
    // dq is: [ ]

    // 2. Add elements to the back.
    dq.push_back(1); // dq is: [ 1 ]
    dq.push_back(2); // dq is: [ 1, 2 ]
    dq.push_back(3); // dq is: [ 1, 2, 3 ]

    // 3. Add an element to the front.
    dq.push_front(4); // dq is: [ 4, 1, 2, 3 ]

    // 4. Remove the last element.
    dq.pop_back();   // dq is now: [ 4, 1, 2 ]
                     // The comment in the image is slightly off; it
                     // shows the state before this operation.

    // 5. Print the front and back elements.
    // dq.front() gets the first element.
    // dq.back() gets the last element.
    cout << dq.front() << " " << dq.back() << endl;
    
    return 0;
}
