// Hierarchical Inheritance : one class serves as parent class for more than one class

#include<iostream>
using namespace std;

class A {

    public:
    int weight;
    int age;

    void funcA() {
        cout << "inside A" << endl;
    }

};

class B : public A {

    public:
    void funcB() {
        cout << "inside B" << endl;
    }
};

class C : public A {

    public:
    void funcC() {
        cout << "inside C" << endl;
    }
};

int main()
{
    A objA;
        objA.funcA();

    // B can use class A
    B objB;
        objB.funcA();
        objB.funcB();

    // C can also use class A 
    C objC;
        objC.funcA();
        objC.funcC();
    
}