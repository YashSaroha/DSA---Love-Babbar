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

    // Hero(){
    //     cout << "simple constructor here" << endl;
    // }

    // PARAMETERIZED CONSTRUCTOR
    Hero(int health){
        // health = health;
        this -> health = health;
        cout << "constructor called" << endl;
        cout << "this -> " << this << endl;
    }

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    void print(){
        cout << "health is " << this -> health << endl;
        cout << "level is " << this -> level << endl;
    }

};

int main()
{
    // cout << "before static" << endl;
    // Hero yash;    
    // cout << "after static" << endl;

    // cout << "before dynamic" << endl;
    // Hero *h = new Hero;
    // Hero *h = new Hero();
    // both lines means same
    // cout << "after dynamic" << endl;



    // Hero yash(30);
    // cout << "address of yash " << &yash << endl;
    // cout << "Health is " << yash.getHealth() << endl;

    // Hero *h = new Hero(60);
    // cout << "address of h " << h << endl;
    // cout << "Health is " << h->getHealth() << endl;

    // Hero temp(20, 'B');
    // cout << "Health is " << temp.getHealth() << endl;
    // cout << "Level is " << temp.level << endl;




    Hero S(12, 'A');
    S.print();

    // COPY CONSTRUCTOR
    Hero R(S);
    R.print();




}