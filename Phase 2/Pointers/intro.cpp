#include<iostream>
using namespace std;

int main()
{
    /*
    int num = 5 ;

    // address of Operator = &
    cout << "address of num is " << &num << endl;


    // pointer is written using *
    // int *ptr;     
    // it is called declaring the pointer...it currently points towards a garbage address
    // declaring a pointer is a bad practice...this should be avoided as we don't want to point towards
    // any random address so we should intialize it with 0...this will be called null pointer
    // int *ptr = 0 means aisi memory ko point krdia jo exist hi nhi krti


    int *ptr = &num ;
    // it means a block 'ptr' is created storing the address of num i.e stores the content of num
    // now both ptr and num point towards the same address which is of num
    // now   num = num + 1 will mean 6    and    (*ptr)++ will also mean 6

    // int *ptr = &num ;      and    int *ptr = 0;  ,  p = &num;
    // they both means same


    // pointer jis data type ko point krega whi data type pointer ka hoga
    char ch = 'a';
    char *p = &ch;
    // means p is a pointer to character 
    

    // * is called dereference operator
    // agr hme 'a' print krna hai to we can write it in two ways
    cout << "value using ch is " << num << endl;
    cout << "value using *ptr is " << *ptr << endl;
    cout << "address is " << ptr << endl;
    // p means p pr jo address pda hai wo bta do i.e ch ka address
    // *p means p pr jo address pda hai usme jo content hai wo bta do i.e value at address pointed by p
    // it means ch and *p will give us same value


    cout << "size of integer is " << sizeof(num) << endl;
    cout << "size of pointer is " << sizeof(ptr) << endl;
    // datatype chahe koi bhi ho..size of pointer will remain same as it always contains address which is 
    // of 8 bytes mostly but 4 bhi aa skta as it is system dependent
    */



    // int num = 5;
    // int *p = &num ;
    // int a = *p ;
    // a++ ;
    // cout << a << endl;
    // cout << *p << endl;
    // cout << num << endl;
    // here num is not incremented and remains same


    // int num = 5;
    // int *p = &num ;
    // cout << "before num is " << num << endl;
    // (*p)++;
    // cout << "after num is " << num << endl;
    // here num is incremented to 6


    // int num = 5;
    // int *p = &num ;
    // (*p)++;
    // // copying a pointer
    // int *q = p;
    // cout << "p is " << p << endl << "*p is " << *p << endl;
    // cout << "q is " << q << endl << "*q is " << *q << endl;
    // here num is incremented to 6



    // arithmetic operations
    int i = 3;
    int *t = &i ;
    // *t = *t + 1;
    // cout << *t << endl;
    cout << t << endl;
    t = t + 1;
    cout << t << endl;
    // isse address me 1 increment nhi hoga...wo next integer pr chla jaega 4 byte increase krke
    // eg t = 100 hai to t+1 me 104 aayega...similarly it depends on other data types





}