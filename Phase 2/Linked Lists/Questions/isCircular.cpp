// given a linked list..find whether it is circular or not
// return true if circular else false

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

bool isCircular(Node* &head) {
    // empty list is also circular
    if(head == NULL ) {
        return true;
    }
    Node* temp = head -> next;
    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }
    if(temp == head){
        return true;
    }
    return false;

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

    // insertNode(tail, 54, 33);
    // print(tail);    // 33 10 2 54 33

    if(isCircular(tail)) {
        cout << "list is circular" << endl;
    }
    else {
        cout << "list is not circular" << endl;
    } 

}