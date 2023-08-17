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
// Let a LL is given and an input element is given. Removing this node

void insertNode(Node* &tail, int element, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else {
        Node* current = tail;
        while( current -> data != element ) {
            current = current -> next;
        }
        Node* temp = new Node(d);
        temp -> next = current -> next;
        current -> next = temp;
    }
}

void deleteNode(Node* &tail, int value) {
    // CASE 1 : EMPTY LIST
    if(tail == NULL) {
        cout << "Empty list, nothing to delete" << endl;
    }
    else {
        // CASE 2 : DELETING WHEN NODES >= 2
        Node* prev = tail;
        Node* current = prev -> next;
        while( current -> data != value) {
            prev = current;
            current = current -> next;
        }
        // node found, deleting it
        prev -> next = current -> next;
        current -> next = NULL;
        if(tail == current) {
            tail = prev;
        }

        // CASE 3 : SINGLE NODE LINKED LIST AND DELETING THAT NODE
        if(current == prev) {
            tail = NULL;
        }

        delete current;     // memory free
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

    /*
    insertNode(tail, 33, 10);

    insertNode(tail, 10, 54);
    
    insertNode(tail, 10, 27);

    insertNode(tail, 27, 2); 

    insertNode(tail, 54, 14);
    print(tail);    // 33 10 27 2 54 14

    deleteNode(tail , 2);
    print(tail);    // 33 10 27 54 14

    deleteNode(tail , 14);
    print(tail);    // 33 10 27 54

    deleteNode(tail , 33);
    print(tail);    // 54 10 27
    */

    // deleting single node
    deleteNode(tail , 33);
    print(tail);    // empty list

    cout << "tail " << tail -> data << endl;
}