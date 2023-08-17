// Multiple Inheritance : one class inherites from different classes
// A class + B class ----> C class

#include<iostream>
using namespace std;

class animal {

    public:
    int weight;
    int age;

    void bark() {
        cout << "barking" << endl;
    }

};

class human {

    public:
    string color;
    void sleep() {
        cout << "sleeping" << endl;
    }

};

// multiple inheritance
class alien : public animal, public human {

};

int main()
{
    alien jaadu;
    jaadu.bark();
    jaadu.sleep();
    cout << jaadu.age << endl;
    
}