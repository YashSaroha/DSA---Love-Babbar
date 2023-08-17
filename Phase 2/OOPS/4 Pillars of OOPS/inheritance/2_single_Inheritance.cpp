// Single Inheritance : one class inherits another class

#include<iostream>
using namespace std;

class animal {

    public:
    int weight;
    int age;

    void speak() {
        cout << "speaking" << endl;
    }

};

class dog : public animal {

};

int main()
{
    dog d;
    d.speak();
    // dog inherited animal class so it can uses animal class's functions and data members
    cout << d.age << endl;
}