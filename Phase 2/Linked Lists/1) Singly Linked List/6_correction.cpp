// what if the linked list is initially empty
// it means head and tail are initially NULL

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, Node* &tail, int d) {
    if(head == NULL) {  // EMPTY LIST
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
}
void insertAtTail(Node* &head, Node* &tail, int d) {
    if(tail == NULL) {  // EMPTY LIST
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(d);
        tail -> next = temp;
        tail = tail -> next;    // or tail = temp;
    }
}

void insertAtPosition(Node * &head, Node * &tail, int position, int d) {

    if(position == 1) {
        InsertAtHead(head, tail, d);
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
        insertAtTail(head, tail , d);
        cout << d << " inserted at position " << position << endl;
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert ;
    cout << d << " inserted at position " << position << endl;

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
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail , 12);
    print(head);

    insertAtTail(head, tail , 15);
    print(head);

    insertAtTail(head, tail , 19);
    print(head);        // output -> 12 15 19
    
    insertAtPosition(head, tail, 3, 22);
    print(head);        // output -> 12 22 15 19

    insertAtPosition(head, tail, 1, 40);
    print(head);        // output -> 40 12 22 15 19  
    
    insertAtPosition(head, tail, 6, 100);
    print(head);        // output -> 40 12 22 15 19 100

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

}