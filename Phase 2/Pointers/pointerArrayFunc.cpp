#include<iostream>
using namespace std;

int getSum(int arr[] , int n)
{
    int sum = 0;
    cout << "size of array is " << sizeof(arr) << endl;
    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i];
        // sum += i[arr];       // both means the same
    }
    return sum;
}
// size of array will come 4/8 byte because 
// jb bhi hm array dete hai function ko to wo pura array pass nhi hota , blki ek pointer pass hota hai *arr 
// mtlb usme bs first element ka address hi pass hota hai and address is of 4/8 byte to ans yhi aayega na ki
// pure array ka size

// so we can write (int *arr , int n) as well instead of (int arr[] , int n)



// BENEFIT OF ARRAY GOING AS A POINTER WHILE PASSING IN A FUNCTION (ans- comment written below)

int main()
{
    int arr[5] = {1,2,3,4,5};
    cout << getSum(arr,5) << endl;
    cout << getSum(arr+2 , 3) << endl;
    // a part of array is passed in the function starting from 2nd index i.e 3,4,5...so ye 3 hi element hai to 
    // size me 5 ki jagah 3 aayega and sum will become 3+4+5 = 12
}