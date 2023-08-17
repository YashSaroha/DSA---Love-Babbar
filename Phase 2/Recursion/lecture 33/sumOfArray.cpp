// find sum of all the elements of an array
#include<iostream>
using namespace std;

int arraySum(int arr[], int size)
{
    if(size == 0)
        return 0;
    if(size == 1)
        return arr[0];

    int sum = arr[0] + arraySum(arr+1 , size-1);
    return sum;

}

int main()
{
    int arr[5] = {1,2,3,4,10};
    int size = 5;
    cout << arraySum(arr, size) << endl;
}