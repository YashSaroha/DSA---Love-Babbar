#include<iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key)
{
    // base case : element not found
    if( s > e )
    return false;


    int mid = s + (e-s)/2 ;

    // base case : element found
    if(arr[mid] == key)
    return true;

    // right half
    if(arr[mid] < key)      
    return binarySearch(arr, mid + 1 , e , key);

    // left half
    else       
    return binarySearch(arr, s , mid - 1 , key);


}

int main()
{
    int arr[5] = { 32, 43, 23, 54, 66};
    int size = 5;
    int key = 60;
    bool isPresent = binarySearch(arr, 0, 4, 90);
    if(isPresent)
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;
        
}