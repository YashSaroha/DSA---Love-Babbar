#include<iostream>
using namespace  std;

class B {
    public:
    int a;
    int b;

    void operator + (B &obj) {
        int value1 = this -> a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
        // cout << "Hello Ji" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->a << endl;
    }

};


int main() {

    B obj1;
    B obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    // + operator is overloaded


    obj1();
    // () operator is overloaded

    return 0;
}