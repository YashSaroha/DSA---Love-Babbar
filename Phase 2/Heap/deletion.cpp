#include<iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

    // constructor
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size = size + 1;
        int index = size;
        arr[index] = data;

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

    void deletion() {
        if(size == 0){
            cout << "nothing to delete" << endl;
            return;
        }
        // step 1 : last index ko root index pr copy krdia
        arr[1] = arr[size];
        // step 2 : last index ko remove krdia
        size-- ;

        // step 3 : root node ko uski correct position pr legye
        int i=1;
        while(i < size)
        {
            int leftIndex = 2*i ;
            int rightIndex = 2*i + 1;

            if(leftIndex <= size && rightIndex <= size)
            {
                if(arr[leftIndex] > arr[i] && arr[leftIndex] > arr[rightIndex])
                {
                    swap(arr[i] , arr[leftIndex]);
                    i = leftIndex;
                }
                else if(arr[rightIndex] > arr[i] && arr[rightIndex] > arr[leftIndex])
                {
                    swap(arr[i] , arr[rightIndex]);
                    i = rightIndex;
                }
            }
            else    
                return;
        }
    }

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
    h.insert(70);
    h.insert(80);
    h.insert(90);

    cout << "before deletion" << endl;
    h.print();
    h.deletion();
    cout << "after deletion" << endl;
    h.print();
}