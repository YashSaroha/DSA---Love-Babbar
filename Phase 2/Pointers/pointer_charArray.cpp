#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {1,2,3};
    char ch[6] = "hello";   // null character bhi include krna hota h char array ka size likhte time
    // cout << arr << endl;
    // cout << ch << endl;
    // interger array me cout krne pr address aayega first memory block ka
    // character array me cout krne se us array ki values aa jaengi
    // it means cout is differently implemented for integer array and char array

    char *c = &ch[0];
    cout << c << endl;
    // integer ke case me ye address print krta first block ka but for character array it will print the whole array
    // first address pr jayega or jbtk null character nhi aata tbtk print kr dega


    // if null character is not present for example
    char temp = 's';
    char *p = &temp;
    cout << p << endl;
    // jbtk null character nhi milega ye print kr dega...z and hello are stored consecutively so shello is printed


    // char *c = "abcde" ;
    // what will happen in behind the scenes in above case
    // -- abcde is stored in temporary memory
    // -- c points to the starting address of that temporary memory
    // so it is NOT a good practice
}