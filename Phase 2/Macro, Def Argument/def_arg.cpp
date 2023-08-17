#include<iostream>
using namespace std;

// rightmost argument se hi start krna pdega default bnana, agr bich me bnadi to error
// int , int , def int) -> ok
// (int , def int, int) -> error
// (int , def int , def int) -> ok
void print(int arr[], int n, int start = 0)     // start is made an optional argument, agr value nhi aayi to 0 maan lega
{
    for(int i=start ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    print(arr, size, 2);
    // printing with all arguments

    print(arr, size);
    // printing without start argument
    // upr int start = 0 hai to by default wo start ki value 0 assume kr lega agr nhi specified func call me
    // it means it is an optional argument



}