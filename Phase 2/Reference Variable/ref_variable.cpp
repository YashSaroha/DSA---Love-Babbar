// reference variable means hm same memory block ko kisi or naam se bula rhe h
#include<iostream>
using namespace std;

void update1(int n) {
    n++;
}

void update2(int &n) {
    n++;
}

int main()
{   /*
    int i=5 ;
    int &j = i;     // a reference variable j is created which means i
    cout << "i is : " << i << endl;
    cout << "j is : " << j << endl;
    i++;
    cout << "i " << i << endl;
    j++;
    cout << "i " << i << endl;
    cout << "j " << j << endl;
    */

    int a = 5;
    cout << "Before a : " << a << endl;
    update1(a);
    cout << "After update1 : " << a << endl;
    update2(a);
    cout << "After update2 : " << a << endl;

    // if we pass a reference variable, value is updated else not updated
    // it is because in update1 case, a new variable is created at different memory location with same value 
    // and all the changes are made on this new copy so our original value remains same but in update2 case, 
    // a new variable is created pointing to the original memory block and all the changes made reflect in the
    // original memory block
    // update1 : pass by value
    // update2 : pass by reference


}