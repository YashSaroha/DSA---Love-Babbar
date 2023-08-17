// koi ek index diya hoga...us index se niche tk ke tree ko heap me convert kr dega heapify algorithm
// this is code for max heap heapify
#include<iostream>
using namespace std;

void heapify(int num[] , int n , int i){

    int largest = i;
    int left = 2*i ;
    int right = 2*i + 1;

    // jo index check krna h usko uske childs ke sath compare kraya
    // 1 based indexing me left/right <= n  aayega ... 0 based me left/right < n aayega
    if(left <= n && num[left] > num[largest])
        largest = left;

    if(right <= n && num[right] > num[largest]);
        largest = right;

    // agr upr koi change hua iska mtlb element glt jgh tha toh use swap krdia and us element ko hi further check kiya 
    if(largest != i)
    {
        swap(num[largest] , num[i]);
        // heapify(num, n, largest);
    }

}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation
    for(int i=n/2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }

    cout << "after heapify" << endl;
    for(int i=1 ; i<=n ; i++)
        cout << arr[i] << " " ;

    cout << endl;

}