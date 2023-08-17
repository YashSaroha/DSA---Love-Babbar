// QUEUE CAN BE IMPLEMENTED USING ARRAYS AND LINKED LIST
// IMPLEMENTING USING ARRAYS

#include <bits/stdc++.h> 
using namespace std;

class Queue {
public:
    int *arr;
    int qfront;
    int rear;
    int size;

    Queue() {
        // size is not given in constructor so assuming a big size manually
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear)
            return true;
        else 
            return false;
    }

    void push(int data) {
        if(rear == size)
            cout << "queue is full";
        else{
            rear++;
            arr[rear] = data;
        }
    }

    int pop() {
        if(qfront == rear)
            return -1;
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            // to avoid space wastage from front side
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int Front() {
        if(isEmpty())
            return -1;
        else
            return arr[qfront];
    }
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return arr[rear];
    }

};

int main()
{
    Queue q;

    cout << "is queue empty ? " << q.isEmpty() << endl;
    q.push(12);
    cout << "rear element is " << q.Rear() << endl;
    q.push(44);
    q.push(67);
    cout << "is queue empty ? " << q.isEmpty() << endl;

    cout << "front element is " << q.Front() << endl;
    cout << "rear element is " << q.Rear() << endl;
    q.pop();
    cout << "front element is " << q.Front() << endl;
    cout << "rear element is " << q.Rear() << endl;


}