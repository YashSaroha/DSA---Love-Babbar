/*
Heap is a data structure or a complete binary tree that comes with a heap order property

2 properties:
    -> Every level is completely filled except the last level that may or may not be filled completely
    -> Nodes are always added from the left or nodes lean towards the left

Heap Order Property - Max Heap & Min Heap
# Max Heap - Every parent node has its value greater than its child values (parent bigger, child smaller)
# Min Heap - Every parent node has its value less than its child values (child bigger, parent smaller)

Heaps are implemented using arrays
=> 0th index of array is always kept empty or -1
=> Left child    =  2 * i
=> Right child   =  2 * i + 1
=> Parent        =  i/2

*/

#include<iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

    // constructor
    heap() {
        // heap array me hmesha 0th index khali rkhna hota hai and array 1 index se fill krna hota hai
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        // step 1 : add data at the end of array
        size = size + 1;
        int index = size;
        arr[index] = data;

        // step 2 : move the data to its correct position by comparing its value with its parent (i/2) value
        // FOR THE CASE OF MAX HEAP, parent should be bigger than data...if small , they are swapped
        while(index > 1)
        {
            int parent = index/2 ;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else
            {
                return ;
            }
        }
    }
    // time complexity of insertion - O(log n)

    void print()
    {
        for(int i=1 ; i <= size ; i++)
            cout << arr[i] << " " ;
        
        cout << endl;
    }

};

int main()
{
    heap h;
    h.insert(50);
    h.insert(60);
    h.insert(55);
    h.insert(40);
    h.insert(70);

    h.print();
}