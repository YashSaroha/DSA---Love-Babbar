#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {2,5,6};

    // cout << arr << endl;        // address of first memory block of array
    // cout << &arr << endl;       // address of first memory block of array
    // cout << &arr[0] << endl;    // address of first memory block of array

    // cout << arr[0] << endl;          // value at first memory block of array
    // cout << *arr << endl;            // value at first memory block of array
    // cout << *arr + 1 << endl;        // value at first memory block of array is incremented
    // cout << *(arr + 1) << endl;      // value at second memory block of array

    // cout << arr[2] << endl;          // value at second memory block of array
    // cout << *(arr + 2) << endl;      // value at second memory block of array
    // cout << 2[arr] << endl;          // value at second memory block of array


    // so we have the formula
    // arr[i] = i[arr] = *(arr + i)


    // int *p = &arr[0];
    // cout << p << endl;      // p me jo address pda hai ye wo value dega
    // cout << *p << endl;     // p me jo address hai us address me jo value hai
    // cout << &p << endl;     // p ka khud ka jo address hai
    // cout << "size of arr is " << sizeof(arr) << endl;
    // cout << "size of *arr is " << sizeof(*arr) << endl;
    // cout << "size of &arr is " << sizeof(&arr) << endl;
    // cout << "size of p is "  << sizeof(p) << endl;
    // cout << "size of *p is " << sizeof(*p) << endl;
    // cout << "size of &p is " << sizeof(&p) << endl;
    // p contains the address of first element of array so its size will always be 4/8 bytes
    // *p means the integer value present in p so it will be 4 bytes



    int num[10] = {1,2,3,4,5};
    
    // ERROR
    // num = num + 1;

    int *ptr = &num[0];
    ptr = ptr + 1;
    cout << ptr << endl;
    // isse 1 nhi add hoga, 1 block aage chla jayega i.e 4 add hoga

}