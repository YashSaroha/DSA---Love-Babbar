#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int size;

    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool insertFront(int value) {
        // if full
        if(isFull())
            return false;
        
        // empty
        else if(isEmpty())
            front = rear = 0;
        
        // circular nature
        else if(front == 0 && rear != size-1)
            front = size-1;
        
        // normal case
        else
            front-- ;

        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        
        // full
        if(isFull())
            return false;

        // empty
        else if(front == -1)
            front = rear = 0;
        
        // circular nature
        else if(front != 0 && rear == size-1)
            rear = 0;

        // normal case
        else
            rear++ ;

        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        
        // empty 
        if(isEmpty())
            return false;

        arr[front] = -1;

        // single element
        if(front == rear)
            front = rear = -1;
        
        // circular nature
        else if(front == size-1)
            front = 0;
        
        // normal case
        else
            front++ ;

        return true;
    }
    
    bool deleteLast() {
        
        // empty
        if(isEmpty())
            return false;
        
        arr[rear] = -1;

        if(front == rear)
            front = rear = -1;
        
        else if(rear == 0)
            rear = size-1 ;
        
        else
            rear-- ;

        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }
    
    int getRear() {
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
        if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)) )
            return true;
        else
            return false;
    }
};

int main()
{
    MyCircularDeque d(10);

    cout << "is queue empty ? " << d.isEmpty() << endl;
    d.insertFront(1);
    cout << "rear is " << d.getRear() << endl;

    d.insertLast(2);
    cout << "rear is " << d.getRear() << endl;
    // 1 2

    d.deleteFront();
    cout << "rear is " << d.deleteFront() << endl;
    // 2
    
    cout << "front is " << d.getFront() << endl;
    d.deleteLast();
    cout << "front is " << d.getFront() << endl;


}