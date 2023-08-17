#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    // take a pivot
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1 ; i<=e ; i++){
        if(arr[i] < pivot){
            count++;
        }
    }
    // place pivot at right index
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i=s ;
    int j=e ;
    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++ ;
        }

        while(arr[j] >  pivot) {
            j-- ;
        }

        swap(arr[i++], arr[j--]);

    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if(s >= e)
    return ;
    
    // doing partition
    int index = partition(arr, s, e);

    // left part ko sort
    quickSort(arr, s, index-1);

    // right part ko sort
    quickSort(arr, index+1, e);
}

int main()
{
    int arr[8] = {6,32,67,2,1,2,2,9};
    int n = 8;
    quickSort(arr, 0, n-1);
    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}