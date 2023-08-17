// STACKS CAN BE IMPLEMENTED USING ARRAYS AND LINKED LIST
// THIS IS THE IMPLEMENTATION USING ARRAYS

#include<iostream>
#include<stack>
using namespace std;

class Stack{

    // properties
    public:
        int top;
        int *arr;
        int size;

    // behaviour
    // constructor
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    // functions
    void push (int element){
        // phle check krlo ki space available hai ki nhi
        if(size - top > 1) { // atleast ek space to khali h
            top++ ;
            arr[top] = element;
        } 
        else
            cout << "stack overflow" << endl;
    }

    void pop() {
        // atleast ek element hona chaiye
        if(top >= 0) 
            top-- ;
        else 
            cout << "stack underflow" << endl;
        
    }

    int peek() {
        if(top >= 0)
            return arr[top];
        else {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1)
            return true;
        else
            return false;
    }


};

int main()
{
    // creation of stack os size 5
    Stack s(5);

    s.push(2);
    s.push(3);
    s.push(8);
    cout << "top element is " << s.peek() << endl;

    s.pop();
    cout << "top element is " << s.peek() << endl;

    s.pop();
    cout << "top element is " << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;


    // stack empty or not
    if(s.isEmpty())
        cout << "haa stack empty hai" << endl;
    else
        cout << "stack empty nhi hai" << endl;

    // size of stack (no of elements present)
    // cout << "size of stack is " << s.size() << endl;

    
}