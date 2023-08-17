#include<iostream>
using namespace std;

void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
}

void updateAddress(int *p)
{
    p = p + 1;
    cout << "inside address : " << p << endl;
}

void updateValue(int *p)
{
    *p = *p + 1;
    cout << "inside value : " << *p << endl;
}

int main()
{
    int num = 5;
    int *ptr = &num ;
    // print(ptr);

    cout << "Before address : " << ptr << endl;
    updateAddress(ptr);
    cout << "After address : " << ptr << endl;
    
    cout << "Before value : " << *ptr << endl;
    updateValue(ptr);
    cout << "After value : " << *ptr << endl;

    // it means address ki value function ke andr hi increment ho skti hai, function ke bahar whi purani value rhegi and
    // value ko update kr skte hai function ka use krke

}