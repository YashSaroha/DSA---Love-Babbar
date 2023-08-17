#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node (int d) {
        this -> data = d;
        this -> next = NULL;
    }
    // destructor
    ~ Node() {
        int value = this -> data;
        // memory free
        if( this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
// Let a LL is given and an input element is given. If element is present in LL, 
// a new node is added after that node

void insertNode(Node* &tail, int element, int d) {
    // CASE 1: EMPTY LIST : element do not matter, simply new node with data d is created pointing to itself
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else {
        // CASE 2: NON-EMPTY LIST
        // Assuming that element is present in the list
        Node* current = tail;
        // checking each value if it is equal to the given element
        while( current -> data != element ) {
            current = current -> next;
        }
        // element found => current represents element wala node
        // is node ke aage ek nayi node add kr denge
        Node* temp = new Node(d);
        temp -> next = current -> next;
        current -> next = temp;

    }
}

// printing a circular linked list
void print (Node* &tail) {
    
    if(tail == NULL) {
        cout << "list is empty" << endl;
        return;
    }
    Node* temp = tail ;
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while (tail != temp);
    cout << endl;
    
}

int main()
{
    Node* tail = NULL;
    insertNode(tail, 5, 33);
    print(tail);    // 33       

    insertNode(tail, 33, 10);
    print(tail);    // 33 10    

    insertNode(tail, 10, 54);
    print(tail);    // 33 10 54    

    insertNode(tail, 10, 2);
    print(tail);    // 33 10 2 54    

    insertNode(tail, 54, 33);
    print(tail);    // 33 10 2 54 33
    // start or end is not logical as it is circular list

}