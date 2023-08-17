#include<iostream>
using namespace std;

void heapify(int num[] , int n , int i){
    cout << "inside" << endl;
    int largest = i;
    int left = 2*i ;
    int right = 2*i + 1;

    if(left <= n && num[left] > num[largest])
        largest = left;

    if(right <= n && num[right] > num[largest]);
        largest = right;

    if(largest != i)
    {
        swap(num[largest] , num[i]);
    }

}

void heapSort(int arr[], int n){

    int size = n ;
    while( size > 1)
    {
        // step 1 : swap first and last element
        swap(arr[1] , arr[size]);

        // step 2 : size km krdia (means last element is now at its correct place)
        size--;

        // step 3 : first element ko correct place pr pahucha dia
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation
    for(int i = n/2 ; i>0 ; i--){
        heapify(arr, n , i);
    }

    // printing
    for(int i=1 ; i<=n ; i++)
        cout << arr[i] << " " ;
    cout << endl;
    

    cout << "after heap sort" << endl;
    heapSort(arr, n);

    for(int i=1 ; i<=n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
    

}