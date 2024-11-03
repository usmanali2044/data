#include <iostream>
using namespace std;
class CircularQueue{
    private:
    int size;
    int *arr;
    int front,rear;
    public:
    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front =rear = -1;      
    }

    ~CircularQueue(){
        delete[] arr;
    }

    bool isFull(){
        if((rear-front == size-1) || (front-rear == 1) ){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }


    void enqueue(int element){
        if(isFull()){
            cout << "can't enqueue " << endl;
            return;
        }
        if(isEmpty()){
            front=0;
        }
        rear =(rear+1)%size;
        arr[rear] = element;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }

        if(front==rear){
           front = -1;
           rear = -1;
        }
        else{
            front = (front+1)%size;
        }
    }

    void display(){
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i==rear){
                break;
            }
            i= (i+1)%size;
        }
        
    }
};
int main(){
    CircularQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(10);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    
    queue.display();
}