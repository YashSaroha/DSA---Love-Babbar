// 2 cases in deleting from any position
// deleting from middle or end , deleting from start

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    // constructor
    Node(int data) {
        this -> data = data;
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

void InsertAtHead(Node* &head, int d) {
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d) {
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node * &head, Node * &tail, int position, int d) {

    if(position == 1) {
        InsertAtHead(head, d);
        cout << d << " inserted at position 1" << endl;
        return;
    }

    Node* temp = head;
    int count = 1;
    while( count < position-1 ) {
        temp = temp -> next;
        count++ ;
    }
    if(temp -> next == NULL) {
        insertAtTail(tail , d);
        cout << d << " inserted at position " << position << endl;
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert ;
    cout << d << " inserted at position " << position << endl;
}

void deleteNode(int position, Node* &head, Node * &tail) {

    // deleting start node
    if( position == 1) {
        Node* temp = head;
        head = head -> next;
        // memory free, manually destructor will be written as memory is alloted in heap
        temp -> next = NULL;
        delete temp;
    }
    else {
        // deleting any middle node or last node
        Node* current = head;
        Node* prev = NULL;
        int count = 1;
        while( count < position ) {
            prev = current ;
            current = current -> next ;
            count++ ;
        }
        // deleting last node will not update tail so to update tail :
        if( current -> next == NULL) {
            Node* temp = tail;
            tail = prev ;
            tail -> next = NULL;    // tail -> next = current -> next
            delete temp;
            return;
        }
        prev -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

// printing the linked list
void print(Node* &head) {
    if(head == NULL) {
        cout << "list is empty" << endl;
        return ;
    }
    Node* temp2 = head;                 
    while(temp2 != NULL) {              
        cout << temp2 -> data << " ";  
        temp2 = temp2 -> next;         
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);     

    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail , 12);
    print(head);

    insertAtTail(tail , 15);
    print(head);

    insertAtTail(tail , 19);
    print(head);        // output -> 10 12 15 19
    
    insertAtPosition(head, tail, 3, 22);
    print(head);        // output -> 10 12 22 15 19

    insertAtPosition(head, tail, 1, 40);
    print(head);        // output -> 40 10 12 22 15 19  
    
    insertAtPosition(head, tail, 7, 100);
    print(head);        // output -> 40 10 12 22 15 19 100

    deleteNode(4, head, tail);
    print(head);
    
    deleteNode(1, head, tail);
    print(head);
    
    deleteNode(5, head, tail);
    print(head);

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

}