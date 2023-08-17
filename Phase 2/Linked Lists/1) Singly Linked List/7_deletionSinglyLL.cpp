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

void insertAtTail(Node* &tail, int d) {
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
};

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
        // if last node is to be deleted, tail will not update so updating tail
        if( current -> next == NULL) {
            Node* temp = tail;
            tail = prev ;
            tail -> next = NULL ;   // or tail -> next = current -> next
            delete temp;
            return;
        }
        // continue...
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
    print(head);        // 10

    insertAtTail(tail , 12);
    print(head);        // 10 12

    insertAtTail(tail , 15);
    print(head);        // 10 12 15

    insertAtTail(tail , 19);
    print(head);        // 10 12 15 19

    insertAtTail(tail , 30);
    print(head);        // 10 12 15 19 30
    
    insertAtTail(tail , 44);
    print(head);        // 10 12 15 19 30 44
  
    deleteNode(3, head, tail);
    print(head);
    
    deleteNode(1, head, tail);  // deleting first node
    print(head);
    
    deleteNode(4, head, tail);  // deleting last node
    print(head);

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

}