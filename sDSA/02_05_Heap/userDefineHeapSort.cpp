// Question : insert delete search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class t1> //! anyway this will be for no
class heap{
    private:
        vector <t1> arr;
        int size;
    public:
        heap(){
            this->size = 0;
        }
        bool heapify(int target){
            int leftChild = target*2 +1;
            int rightChild = target*2 +2;
            int largest = target;

            if(leftChild < size && this->arr[leftChild] > this->arr[largest])
                largest = leftChild;
            if(rightChild < size && this->arr[rightChild] > this->arr[largest])
                largest = rightChild;

            if(target != largest){
                swap(this->arr[target], this->arr[largest]);
                this->heapify(largest);
            }

            return true;
        }
        int getSize(){
            return this->size;
        }
        bool isEmpty(){
            return this->size == 0;
        }
        bool insert(t1 num){
            this->arr.push_back(num);
            this->size = this->size + 1;

            int i = this->size - 1;
            while(i != 0){
                int parent = (i - 1) / 2;
                if(this->arr[parent] < this->arr[i]){
                    swap(this->arr[parent], this->arr[i]);
                    i = parent;
                } else {
                    break;
                }
            }

            return true;
        }
        t1 deleteN(){
            if(size <= 0){
                throw out_of_range("heap is empty");
            }
            swap(this->arr[0], this->arr[size-1]);
            t1 data = this->arr.back();
            this->arr.pop_back();
            this->size = this->size - 1;
            if(this->size > 0)
                this->heapify(0);
            return data;
        }
        void printHeap(){
            for(int i = 0; i < size; i++) {
                cout << "[" << this->arr[i] << "]" << " ";
            }
            cout << endl;
        }
};

int main(){
    heap <int> he;

    int control = -1;
    int num = 0;
    while (true){
        cout << "Enter : ";
        cin >> control;
        switch (control){
            case 1:
                cin >> num;
                he.insert(num);
                break;
            case 2:
                cout << he.deleteN() << " is deleted " << endl;
                break;
            case 3:
                he.printHeap();
                break;
            default:
                cout << "Wrong Input " << endl;
                break;
        }
    }
    
return 0;}
