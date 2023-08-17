#include<iostream>
using namespace std;

class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog : public Animal {

    public:
    void speak() {
        cout << "Barking " << endl;
    }
};

int main() {

    Dog obj;
    obj.speak();
    // dog ke andr ka speak function call ho jaega

    return 0;
}