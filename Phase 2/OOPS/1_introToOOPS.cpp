#include<iostream>
using namespace std;

class Hero{
    // properties
    private:
    int health ;

    public:  
    char level;
    static int timeLeft;
    // using static keyword for creating a static data member that belongs to class
    // this is initialized after the class ->  datatype className :: fieldName = value;
    // no need of creating object to access this data member, just cout << classname :: fieldname

    //getter function
    int getHealth() {
        return health;
    }

    // setter function
    void setHealth(int h) {
        health = h;
    }

};

int Hero :: timeLeft = 50;

int main()
{
    // accessing static data member without creating any object
    cout << "Timeleft is : " << Hero::timeLeft << endl;
    
    Hero yash;
    // yash.health = 43;
    // yash.level = 'A';
    // cout << yash.health << endl;

    cout << "garbage value of health is " << yash.getHealth() << endl;
    cout << "------setting health using setter------" << endl;
    yash.setHealth(40);
    cout << "new value of health is " << yash.getHealth() << endl;

}