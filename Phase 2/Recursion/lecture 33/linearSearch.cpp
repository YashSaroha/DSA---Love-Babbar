#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    // base case
    if(size == 0)
    return false;

    if(arr[0] == key) {
        return true;
    }

    else {
        bool remainingPart = linearSearch(arr+1 , size-1 , key);
        return remainingPart;
    }

}

int main()
{
    int arr[5] = {3,5,23,55,21};
    int size = 5;
    int key = 5;
    bool search = linearSearch(arr, size, key);
    if(search)
        cout << "element is present" << endl;
    else
        cout << "element is not present" << endl;
}