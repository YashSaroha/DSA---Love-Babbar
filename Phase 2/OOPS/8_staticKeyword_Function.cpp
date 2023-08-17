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

    static int myFunction () {
        return timeLeft ;       // can access only the static member
        // return health ;      can't access as health is not a static member
        // return level ;       can't access as level is not a static member
    }

};

int Hero :: timeLeft = 50;

int main()
{
    // accessing static data member without creating any object
    cout << "Timeleft is : " << Hero::timeLeft << endl;

    cout << "Using the static function" << endl;
    cout << Hero::myFunction() << endl;

}