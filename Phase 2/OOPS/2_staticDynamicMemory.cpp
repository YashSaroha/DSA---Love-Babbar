#include<iostream>
using namespace std;

class Hero {

    private:
    // int health = 90;
    int health;

    public:
    // char level = 'A';
    char level;

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

};

int main()
{
    // static memory allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('A');
    cout << "health is " << a.getHealth() << endl;
    cout << "level is " << a.level << endl;

    // dynamic memory allocation
    Hero *b = new Hero;
    // Hero *b = new Hero();
    b->setHealth(80);
    b->setLevel('A');
    
    // METHOD 1
    // b me address stored hai to dereference krne ke liye we used *
    cout << "health is " << (*b).getHealth() << endl;
    cout << "level is " << (*b).level << endl;

    // METHOD 2 
    cout << "health is " << b->getHealth() << endl;
    cout << "level is " << b->level << endl;
    

}