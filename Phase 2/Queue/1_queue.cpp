#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // creating a queue
    queue<int> q;

    // inserting  (at end)
    q.push(11);
    q.push(16);
    q.push(19);

    // size of queue
    cout << "size is " << q.size() << endl;

    // removing elements (from front)
    q.pop();

    cout << "size is " << q.size() << endl;

    // empty or not
    if(q.empty())
        cout << "queue is empty" << endl;
    else
        cout << "queue is not empty" << endl;

    // front element
    cout << "front element is " << q.front() << endl;

    // rear element
    cout << "last element is " << q.back() << endl;

    q.push(3);
    cout << "front element is " << q.front() << endl;
    cout << "last element is " << q.back() << endl;

    q.push(6);
    cout << "front element is " << q.front() << endl;
    cout << "last element is " << q.back() << endl;

    q.push(1);
    cout << "front element is " << q.front() << endl;
    cout << "last element is " << q.back() << endl;



}