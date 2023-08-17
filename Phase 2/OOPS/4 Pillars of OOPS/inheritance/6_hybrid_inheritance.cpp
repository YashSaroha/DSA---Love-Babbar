// Hybrid Inheritance : combination of more than 1 type of inheritance
// A    D
// | \  |       A,B,C are in hierarchical
// |  \ |       A,C,D are in multiple
// |   \|
// B    C           

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

class D {

    public:
    void funcD() {
        cout << "inside D" << endl;
    }
};

// B class can use only A
class B : public A {

    public:
    void funcB() {
        cout << "inside B" << endl;
    }
};

// C can use both A and D (hierarchy + multiple)
class C : public A , public D {

    public:
    void funcC() {
        cout << "inside C" << endl;
    }
};

int main()
{
    // B can use class A
    B objB;
        objB.funcA();
        objB.funcB();

    // C can use class A + class D
    C objC;
        objC.funcA();
        objC.funcD();
        objC.funcC();
    
}