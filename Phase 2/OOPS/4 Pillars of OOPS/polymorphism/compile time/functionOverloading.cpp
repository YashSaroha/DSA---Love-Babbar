#include<iostream>
using namespace std;

class A {

    public:
    void sayHello() {
        cout << "Hello Yash" << endl;
    }

    // int sayHello() {     this will give error
    // }
    
    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

    int sayHello(char name) {
        cout << "Hello Yash" << endl;
        return 1;
    }

};

int main()
{
    A obj;
    obj.sayHello();
}
