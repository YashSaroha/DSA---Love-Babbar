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

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
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

// get length of list
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
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    // cout << "length is " << getLength(head) << endl;

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 9);
    print(head);

    insertAtHead(head, 5);
    print(head);

}