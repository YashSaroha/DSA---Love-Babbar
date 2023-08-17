#include<bits/stdc++.h>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char *name;
    char level;

    Hero() {
        name = new char[100];
    }

    void setName(char name[]) {
        strcpy(this->name , name);
    }

    void setHealth(int health) {
        this -> health = health;
    }

    void setLevel(char level) {
        this -> level = level;
    }

    void print(){
        cout << endl;
        cout << "name: " << this -> name << " , ";
        cout << "health: " << this -> health << " , ";
        cout << "level: " << this -> level ;
    }

};

int main()
{
    Hero H1;
    H1.setHealth(23);
    H1.setLevel('A');
    char name[10] = "yash";
    H1.setName(name);  
    cout << "printing before updating" ;
    H1.print();

    Hero H2 = H1;
    H2.print();
    // default copy constructor is used in shallow copy

    // updating name
    cout << endl << endl << "printing after updating" ;
    H1.name[0] = 'R';   
    H1.print();
    H2.print();

    
}