// Question : Make a Queue class and make a simple queue
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void enqueue(const T& value) {
        Node<T>* node = new Node<T>(value);

        if(node == NULL)
            return; // error

        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        count++;
    }
    bool dequeue() {
        if (isEmpty()) return false;

        Node<T>* temp = front;
        front = front->next;
        delete temp;

        count--;
        
        if (front == nullptr)
            rear = nullptr;

        return true;
    }
    T& peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }
    bool isEmpty() const {
        return count == 0;
    }
    int getSize() const {
        return count;
    }
    void print(){
        Node<T>* temp = front;
        while (temp != NULL) {
            cout << " " << temp->data;
            temp = temp->next;
        }
        cout << endl;   
    }
};



int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);

    cout << q.peek() << endl; // 10
    q.dequeue();
    cout << q.peek() << endl; // 20

    cout << "Size: " << q.getSize() << endl;
    cout << "isEmpty : " << q.isEmpty() << endl;
    cout << "Print : ";
    q.print();

return 0;}

