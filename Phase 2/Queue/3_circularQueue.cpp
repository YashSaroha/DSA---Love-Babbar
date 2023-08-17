#include <bits/stdc++.h> 
using namespace std;

class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        
        if(isFull())
            return false;
        
        // queue is empty
        if(front == -1)
        front = rear = 0;

        // making rear circular
        else if(rear == size-1 && front != 0)
            rear=0;

        // normal insertion
        else
            rear++;
        
        
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        return false;

        arr[front] = -1;

        // single element
        if(front == rear)
            front = rear = -1;

        // making circular
        else if(front == size-1)
            front=0;

        // normal case
        else
            front++;

        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (rear == (front-1) % (size)))
            return true;
        else
            return false;
    }
};

int main()
{
    MyCircularQueue q(10);

    cout << "is queue empty ? " << q.isEmpty() << endl;
    q.enQueue(1);
    cout << "rear is " << q.Rear() << endl;

    q.enQueue(2);
    cout << "rear is " << q.Rear() << endl;

    q.enQueue(3);
    cout << "rear is " << q.Rear() << endl;
    
    cout << "is queue empty ? " << q.isEmpty() << endl;
    cout << "front is " << q.Front() << endl;
    q.deQueue();
    cout << "front is " << q.Front() << endl;


}