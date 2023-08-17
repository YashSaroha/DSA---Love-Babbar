// tell whether array is sorted or not
#include<iostream>
using namespace std;

bool sorted(int arr[], int size)
{
    if(size == 0 || size == 1)
    return true;

    if(arr[0] > arr[1])
        return false;
    else
    {
        bool remainingPart = sorted(arr + 1, size - 1);
        return remainingPart ;
    }
}

int main()
{
    int arr[5] = {3,5,9,7,8};
    int size = 5;
    bool ans = sorted(arr, size);

    if(ans)
        cout << "array is sorted" << endl;
    else
        cout << "array is not sorted" << endl;

}