#include<iostream>
using namespace std;
int main()
{
    // why we are using    int *ptr = &value    and not like     pointer ptr = &value
    // -> hme pta lgta hai ki kis type ka data hai
    // -> hme pata lgta hai ki kitni bytes ko consider krna hai like int me 4, char me 1

    // pointer pointer towards a address
    // double pointer points towards the address of that above pointer
    // in short, double pointer is a pointer to a pointer and we use an additional * for it

    int i=5 ; 
    int *ptr1 = &i ;
    int **ptr2 = &ptr1 ;
    // similarly if we want to make a pointer corresponding to ptr, we will use 3 stars , then 4 and so on
    // cout << "address of i " << &i << endl;
    // cout << "ptr is " << ptr1 << endl;
    // cout << "address of ptr1 is " << &ptr1 << endl;
    // cout << "ptr2 is " << ptr2 << endl;
    // cout << "*ptr2 is " << *ptr2 << endl;       
    // *ptr2 means ptr2 jise point krra hai us address pr jo value hai i.e ptr2 point to ptr1 which contains address of i 
    // it means ptr1 and *ptr2 are same as they both contains the address of i


    // WAYS TO PRINT VALUE OF I
    // cout << i << endl;
    // cout << *ptr1 << endl;
    // cout << **ptr2 << endl;  // jitne star lgaenge utni depth me jate jayenge

    // // WAYS TO PRINT ADDRESS OF I
    // cout << &i << endl;
    // cout << ptr1 << endl;
    // cout << *ptr2 << endl;

    // WAYS TO PRINT ADDRESS OF PTR1
    // cout << &ptr1 << endl;
    // cout << ptr2 << endl;



}