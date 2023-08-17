// Multi level Inheritance : first class inherits second, second inherits third and so on
// A class ----> B class -----> C class .......

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

class Husky : public dog {

};

int main()
{
    Husky h;
    h.speak();
    cout << h.age << endl;
    // dog inherited animal class and husky inherited dog class so it can uses animal class's functions and data members
    // animal ---> dog ---> husky
}