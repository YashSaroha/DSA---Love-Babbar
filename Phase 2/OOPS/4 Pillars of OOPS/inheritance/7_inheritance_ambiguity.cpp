// Inheritance Ambiguity : one class inherites from different classes
// A class + B class ----> C class
// A me bhi func() and B me bhi func()
// C -> object     obj.func()  ?? which function will be called
// To solve this, scope resolution operator :: is used

#include<iostream>
using namespace std;

class A {

    public:
    void bark() {
        cout << "barking" << endl;
    }
};

class B {

    public:
    void bark() {
        cout << "barking" << endl;
    }
};

// multiple inheritance
class C : public A, public B {

};

int main()
{
    C object;
    // object.bark();     this will give error
    object.A::bark();
    object.B::bark();
    
}