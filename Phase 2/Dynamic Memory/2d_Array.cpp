#include<iostream>
using namespace std;

int main()
{
    int row,col;
    cout << "Rows : " ;
    cin >> row;
    cout << "Cols : " ; 
    cin >> col;
    // creating 2d array in heap
    int **arr = new int*[row];
    for(int i=0; i<row; i++)
    {
        arr[i] = new int[col];
    }       // ek array bngya jiske andr bohot sare arrays ke starting index pde hai
            // in short ek bda array bngya containing pointers to different arrays

    // taking input
    for(int i=0; i<row ; i++)
    {
        for(int j=0; j<col ; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing output
    for(int i=0; i<row ; i++)
    {
        for(int j=0; j<col ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory
    for(int i=0 ; i<row ; i++)
    {
        delete [] arr[i];
    }
    delete []arr;

}