#include<iostream>
using namespace std;

class Human {   // this is the parent class / superclass

    private:
        string gender;
        
    public:
        int age;
        int height;
        int weight;
    
        int getAge(){
            return this -> age;
        }

        void setWeight(int w) {
            this -> weight = w;
        }
};

class Male : public Human {     // this is subclass / child class
    
    public:
    string color;

    void sleep() {
        cout << "function called, male sleeping" << endl;
    }
};

int main()
{
    Male obj1;
    cout << "height is " << obj1.height << endl;
    cout << "weight is " << obj1.weight << endl;
    cout << "age is " << obj1.age << endl;
    cout << "color is " << obj1.color << endl;
    obj1.sleep();
    obj1.setWeight(50);
    cout << "new weight is " << obj1.weight << endl;

    /*
        TYPES OF INHERITANCE
        -> Single Inheritance
        -> Multi-level Inheritance
        -> Multiple Inheritance
        -> Hybrid Inheritance
        -> Hierarchical Inheritance
    */   

}