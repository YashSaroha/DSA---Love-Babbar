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

void insertAtHead(Node* &head, int d) {
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
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

// find length of linked list
int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++ ;
        temp = temp -> next;
    }
    return len;
}

int main()
{
    // heap me allocate kra di
    // Node *node1 = new Node();    // garbage values of data and next address printed
    // STEP 1 : FIRST NODE CREATED
    Node *node1 = new Node(10);     // data : 10 , next address : NULL i.e 0x0 or 0
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // STEP 2 : HEAD POINTED TO NODE1
    Node* head = node1;
    print(head);
    // only 10 will be printed

    // STEP 3 : NEW NODE INSERTED WITH VALUE 12
    insertAtHead(head , 12);
    print(head);
    // output -> phle 10 tha, ab 12 bhi aagya to output will be 12 10

    // NEW NODE INSERTED WITH VALUE 15
    insertAtHead(head , 15);
    print(head);
    // output -> 15 12 10

    cout << "length of linked list is " << getLength(head) << endl;

}