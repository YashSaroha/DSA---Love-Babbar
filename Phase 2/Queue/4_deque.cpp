#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // creating a deque
    deque<int> d;

    // inserting  (at end)
    d.push_front(12);
    d.push_back(14);
    // 12 14

    cout << "front " << d.front() << endl;
    cout << "rear " << d.back() << endl << endl;

    d.push_front(10);
    cout << "front " << d.front() << endl;
    cout << "rear " << d.back() << endl;
    // 10 12 14
    cout << endl;

    d.pop_back() ;
    cout << "front " << d.front() << endl;
    cout << "rear " << d.back() << endl;
    // 10 12
    cout << endl;

    d.pop_front() ;
    cout << "front " << d.front() << endl;
    cout << "rear " << d.back() << endl;
    //    12
    cout << endl;

    d.pop_back();
    if(d.empty())
        cout << "deque is empty" << endl;
    else
        cout << "deque is not empty" << endl;





}