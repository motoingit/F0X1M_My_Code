
#include <iostream>
using namespace std;

struct Student {
    private:
        string name;
        int rollNo;
        float marks;
    public:
        // // Constructor to initialize the structure
        // Student(string n, int r, float m) : name(n), rollNo(r), marks(m) {}

        void put(string n, int r, float m) {
            name = n;
            rollNo = r;
            marks = m;
        }
        void display() const {
            cout << "Name: " << name << ", Roll No: " << rollNo << ", Marks: " << marks << endl;
        }
};

int main(){

    Student s1; // Using default constructor
    // Student s1("Mohit", 101, 92.5); // Using parameterized constructor (if uncommented)
    cout << "Enter student details (name, roll number, marks): ";
    
    string name;
    int rollNo;
    float marks;

    cin >> name >> rollNo >> marks;
    s1.put(name, rollNo, marks);

    cout << "Student Details: ";
    s1.display();

return 0;}

/*

struct (Structure)
	• Groups different data types into a single logical unit.
	• By default, members are public.
    - Often used for lightweight data containers.
    
*/
