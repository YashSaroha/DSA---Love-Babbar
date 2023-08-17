#include<iostream>
using namespace std;

void bubbleSort( int arr[], int n)
{
    // base case - already sorted array
    if(n==0 || n==1)
        return ;
    
    // 1 case solve krlia jisme greatest element last me pahuch jayega
    for(int i=0 ; i<n-1 ; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }

    // recursive call
    bubbleSort(arr , n-1);

}

int main()
{
    int arr[5] = {14,3,65,21,1};
    int size = 5;
    bubbleSort(arr, size);

    for(int i=0 ; i<size ; i++)
    {
        cout << arr[i] << " " ;
    }
}