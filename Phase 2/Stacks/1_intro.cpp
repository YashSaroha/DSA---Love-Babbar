#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop operation
    s.pop();

    // top element or last element
    cout << "Printing top element " << s.top() << endl;

    // stack empty or not
    if(s.empty())
        cout << "Stack is empty " << endl;
    else
        cout << "stack is not empty " << endl;

    // size of stack (no of elements present)
    cout << "size of stack is " << s.size() << endl;

    
}