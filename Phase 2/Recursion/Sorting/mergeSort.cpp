#include<iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e-s)/2 ;

    int len1 = mid - s + 1;
    int len2 = e - s;

    int *firstArray = new int[len1];
    int *secondArray = new int[len2];


    // copying first half values in first array
    int mainArrayIndex = s;
    for(int i=0 ; i < len1 ; i++) {
        firstArray[i] = arr[mainArrayIndex++];
    }

    // copying second half values in second array
    mainArrayIndex = mid+1 ;
    for(int i=0 ; i < len2 ; i++) {
        secondArray[i] = arr[mainArrayIndex++];
    }

    // merging 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while(index1 < len1 && index2 < len2)
    {
        if (firstArray[index1] < secondArray[index2]) {
            arr[mainArrayIndex++] = firstArray[index1++];
        }
        else {
            arr[mainArrayIndex++] = secondArray[index2++];
        }
    }

    while( index1 < len1 ) {
        arr[mainArrayIndex++] = firstArray[index1++];
    }

    while( index2 < len2 ) {
        arr[mainArrayIndex++] = secondArray[index2++];
    }

}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if(s >= e)
    return ;

    int mid = s + (e-s)/2 ;
    // left part sort krna hai
    mergeSort(arr, s, mid);

    // right part sort krna hai
    mergeSort(arr, mid+1, e);

    // merge both arrays
    merge(arr, s, e);

}

int main()
{
    int arr[5] = {5,6,2,8,1};
    int n = 5;
    mergeSort(arr, 0, n-1);
    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}