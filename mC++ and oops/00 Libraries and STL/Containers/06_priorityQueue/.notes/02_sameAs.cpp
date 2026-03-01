#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10); //* inserting element
    pq.push(5);
    pq.push(20);

    cout << pq.top();  // 20

    int x = pq.top(); //* accessing top ele
    pq.pop(); //* deleting top element

    //*Search | Traversal
    while(it != pq.)

}

/*
parent = (i-1)/2
left = 2*i+1
right = 2*i+2
*/
