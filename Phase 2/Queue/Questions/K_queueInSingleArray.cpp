#include<iostream>
#include<queue>
using namespace std;

class kQueue{

    public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

    kQueue(int n, int k){
        this -> n = n;
        this -> k = k;

        front = new int[k];
        rear = new int[k];
        for(int i=0 ; i<k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i=0 ; i<n ; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freespot = 0;
    }

    void enQueue(int value, int Qn){
        // overflow
        if(freespot == -1){
            cout << "no free space available" << endl;
            return ;
        }
        // find first free index
        int index = freespot;

        // update freespot;
        freespot = next[index] ;

        // check whether it is first element to be inserted
        if(front[Qn-1] == -1){
            front[Qn-1] = index;
        }
        // if not, linking the previous element of same queue to this new element
        else{
            next[rear[Qn-1]] = index ;
        }

        // update next i.e no freespace availabe for this element
        next[index] = -1;

        // updating rear
        rear[Qn-1] = index ;

        // push element
        arr[index] = value;
        
    }

    int deQueue(int Qn) {
        // underflow
        if(front[Qn-1] == -1){
            cout << "list is empty, can't pop" << endl;
            return -1;
        }
        // find index to pop
        int index = front[Qn-1];

        // front ko aage bdhao
        front[Qn-1] = next[index];

        // freespot update
        next[index] = freespot ;
        freespot = index ;

        return arr[index];

    }

};

int main()
{
    kQueue q(10, 3);

    q.enQueue(10 , 1);
    q.enQueue(15 , 1);
    q.enQueue(20 , 2);
    q.enQueue(25 , 1);

    cout << q.deQueue(1) << endl;
    cout << q.deQueue(2) << endl;
    cout << q.deQueue(1) << endl;
    cout << q.deQueue(1) << endl;

    cout << q.deQueue(1);


}