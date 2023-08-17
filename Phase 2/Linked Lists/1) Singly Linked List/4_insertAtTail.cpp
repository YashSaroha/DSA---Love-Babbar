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

// inserting a new node at the last
void insertAtTail(Node* &tail, int d) {
    // new node is created first
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;    // or tail = temp;
}

// printing the linked list
void print(Node* &head) {
    if(head == NULL) {
        cout << "list is empty" << endl;
        return ;
    }
    Node* temp2 = head;                 // 1) temp bnake usko head pr point kraya
    while(temp2 != NULL) {              // 4) isko tbtk krna hai jbtk temp Null na ho jaye
        cout << temp2 -> data << " ";  // 2) current temp ko print krlia
        temp2 = temp2 -> next;          // 3) temp ko agli node pr le gye
    }
    cout << endl;

}

int main()
{
    // STEP 1 : FIRST NODE CREATED
    Node *node1 = new Node(10);

    // STEP 2 : HEAD AND TAIL POINTED TO NODE1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    // only 10 will be printed

    // STEP 3 : NEW NODE INSERTED WITH VALUE 12
    insertAtTail(tail , 12);
    print(head);
    // output -> phle 10 tha, ab 12 bhi aagya to output will be 10 12

    // NEW NODE INSERTED WITH VALUE 15
    insertAtTail(tail , 15);
    print(head);
    // output -> 10 12 15

}