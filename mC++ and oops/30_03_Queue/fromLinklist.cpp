#include <iostream>
#include <stdexcept> // For std::runtime_error

// The Queue class encapsulates the entire logic.
// The Node struct is a private implementation detail.
class Queue {
private:
    // A private nested struct for the linked list nodes.
    // Users of the Queue don't need to know about it.
    struct Node {
        int data;
        Node* next;
        // Constructor for easy node creation
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    // Constructor: Initializes an empty queue.
    Queue() : head(nullptr), tail(nullptr) {}

    // Destructor: Cleans up all nodes to prevent memory leaks.
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Checks if the queue is empty.
    bool isEmpty() const {
        return head == nullptr;
    }

    // Adds an element to the back of the queue (O(1)).
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            // If the queue is empty, the new node is both head and tail.
            head = tail = newNode;
        } else {
            // Otherwise, add to the end and update the tail.
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Removes the element from the front of the queue (O(1)).
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;

        // CRITICAL FIX: If the queue becomes empty after dequeuing,
        // the tail pointer must also be set to null.
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Returns the front element without removing it (O(1)).
    int front() const {
        if (isEmpty()) {
            // Throwing an exception is safer than returning a magic number like -1.
            throw std::runtime_error("Cannot get front element from an empty queue.");
        }
        return head->data;
    }

    // A helper function to display the queue's contents.
    void display() const {
        if (isEmpty()) {
            std::cout << "QUEUE: [ empty ]\n";
            return;
        }
        std::cout << "QUEUE: front -> ";
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null\n";
    }
};


// A main function to demonstrate and test the Queue class.
int main() {
    std::cout << "Creating a new Queue...\n";
    Queue myQueue;
    myQueue.display();

    std::cout << "\nEnqueuing 10, 20, 30...\n";
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.display();

    try {
        std::cout << "\nFront element is: " << myQueue.front() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\nDequeuing one element...\n";
    myQueue.dequeue();
    myQueue.display();
    
    std::cout << "\nFront element is now: " << myQueue.front() << std::endl;

    std::cout << "\nDequeuing remaining elements...\n";
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.display();

    std::cout << "\nAttempting to dequeue from an empty queue...\n";
    myQueue.dequeue(); // This will print an error message.

    std::cout << "\nQueue object is about to go out of scope. Destructor will be called automatically.\n";

    return 0;
}
