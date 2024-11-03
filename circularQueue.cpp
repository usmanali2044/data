#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int size;
    int front, rear;

public:
    
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

   
    ~CircularQueue() {
        delete[] arr;
    }

  
    bool isFull() {
        return ((rear + 1) % size == front);
    }

  
    bool isEmpty() {
        return (front == -1);
    }

    
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0; 
        }
        rear = (rear + 1) % size; 
        arr[rear] = element;
        cout << "Enqueued " << element << " into the queue.\n";
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue.\n";
            return;
        }
        cout << "Dequeued " << arr[front] << " from the queue.\n";
        if (front == rear) {
            
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; 
        }
    }

    
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1; 
        }
        return arr[front];
    }

   
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Elements in the queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % size; 
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue queue(size);
    int choice;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Get Front\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4: {
                int frontElement = queue.getFront();
                if (frontElement != -1)
                    cout << "Front element is: " << frontElement << "\n";
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input. Please enter a number between 1 and 5.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
