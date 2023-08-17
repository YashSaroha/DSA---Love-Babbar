// what if our linked list is initially empty
#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

    // constructor
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d) {
    if(head == NULL) {  // EMPTY LIST
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void insertAtTail(Node* &head, Node* &tail, int d) {
    if(tail == NULL) {  // EMPTY LIST
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if(position == 1) {
        insertAtHead(head, tail, d);
        return ;
    }
    int count = 1;
    Node* temp = head;
    while( count < position - 1 ) {
        temp = temp -> next;
        count++;
    }
    if( temp -> next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }
    // create new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    nodeToInsert -> prev = temp;
    temp -> next = nodeToInsert;

}

// printing the list
void print(Node* &head) {
    if(head == NULL) {
        cout << "list is empty" << endl;
        return ;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 13);
    print(head);    // 13

    insertAtTail(head, tail, 9);
    print(head);    // 13 9

    insertAtPosition(head, tail, 2, 50);
    print(head);    // 13 50 9

    insertAtPosition(head, tail, 1, 69);     // first position
    print(head);    // 69 13 50 9

    insertAtPosition(head, tail, 5, 88);    // last position
    print(head);    // 69 13 50 9 88

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

}