#include<iostream>
using namespace std;

void update(int **p)
{
    // p = p + 1;
    // koi change nhi hoga

    // *p = *p + 1;
    // p jisko point krra hai wo address 4 byte increase ho jayega i.e ptr1 ke andr ka address 4 byte increase

    **p = **p + 1;
    // **p mtlb i ka content 1 se bdh jaega 
}

int main()
{
    int i=5 ; 
    int *ptr1 = &i ;
    int **ptr2 = &ptr1 ;
    
    cout << "before " << i << endl;
    cout << "before " << ptr1 << endl;
    cout << "before " << ptr2 << endl;
    update(ptr2);
    cout << "after " << i << endl;
    cout << "after " << ptr1 << endl;
    cout << "after " << ptr2 << endl;
}