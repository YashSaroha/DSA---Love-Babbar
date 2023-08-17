#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char level;

    int getHealth() {
        return health;
    }

    Hero() {
        cout << "constructor called here" << endl;
    }

    ~ Hero() {
        cout << "destructor called here" << endl;
    }

    void print(){
        cout << "health is " << this -> health << endl;
        cout << "level is " << this -> level << endl;
    }

};

int main()
{
    // static
    Hero hero1 ;
    // destructor for statically allocated object is called automatically

    // dynamic
    Hero *hero2 = new Hero();
    delete hero2;
    // destructor for dynamically allocated object needs to be called manually

}