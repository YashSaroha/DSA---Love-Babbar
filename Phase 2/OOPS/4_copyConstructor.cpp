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

    // DEFAULT/SIMPLE CONSTRUCTOR
    // Hero(){
    //     cout << "simple constructor here" << endl;
    // }

    // PARAMETERIZED CONSTRUCTOR
    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    // COPY CONSTRUCTOR
    Hero( Hero &temp ){
        cout << "copy constructor called" << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    void print(){
        cout << "health is " << this -> health << endl;
        cout << "level is " << this -> level << endl;
    }

};

int main()
{
    Hero S(12, 'A');
    S.print();

    // COPY CONSTRUCTOR
    Hero R(S);
    // or we can write  Hero R = S;
    R.print();

    
}