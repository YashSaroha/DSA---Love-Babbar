// 3 cases in inserting at any position
// inserting anywhere in between, inserting at start, inserting at end

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

void InsertAtHead(Node* &head, int d) {
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d) {
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;    // or tail = temp;
}

void insertAtPosition(Node * &head, Node * &tail, int position, int d) {

    // CASE 1 : INSERTING AT FIRST POSITION (START)
    if(position == 1) {
        InsertAtHead(head, d);
        cout << d << " inserted at position 1" << endl;
        return;
    }

    // CASE 2 : INSERTING AT ANY POSITION IN BETWEEN
    Node* temp = head;
    int count = 1;
    // shru me hm 1st node pr hai and we want to add node at nth place
    // so traversing till n-1 node
    while( count < position-1 ) {
        temp = temp -> next;
        count++ ;
    }

    // CASE 3 : INSERTING AT LAST POSITION (END)
    if(temp -> next == NULL) {
        insertAtTail(tail , d);
        cout << d << " inserted at position " << position << endl;
        return;
    }

    // continue...insert at position
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
    
    // NEW NODE TO BE INSERTED AT 3RD POSITION BETWEEN 12 AND 15 , WITH VALUE 22
    insertAtPosition(head, tail, 3, 22);
    print(head);        // output -> 10 12 22 15 19

    // NEW NODE TO BE INSERTED AT 1st POSITION , WITH VALUE 1
    insertAtPosition(head, tail, 1, 40);
    print(head);        // output -> 40 10 12 22 15 19  
    
    // NEW NODE TO BE INSERTED AT LAST POSITION (7th) , WITH VALUE 100
    insertAtPosition(head, tail, 7, 100);
    print(head);        // output -> 40 10 12 22 15 19 100

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

}