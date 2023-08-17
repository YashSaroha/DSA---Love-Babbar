#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    // to give some values in the node constructor is used
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// inserting a new node in front of existing node
void InsertAtHead(Node* &head, int d) {
    // new node is created first
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

int main()
{
    // heap me allocate kra di
    // Node *node1 = new Node();    // garbage values of data and next address printed
    Node *node1 = new Node(10);     // data : 10 , next address : NULL i.e 0x0 or 0
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

}