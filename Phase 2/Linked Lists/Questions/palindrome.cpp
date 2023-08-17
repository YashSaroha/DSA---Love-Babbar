
#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// printing the linked list
void print(Node *&head)
{
    if (head == NULL) {
        cout << "list is empty" << endl;
        return;
    }
    Node *temp2 = head;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
}

Node* rev(Node* head) {
    // base case
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* chotaHead = rev(head->next);
    head -> next -> next = head;
    head -> next = NULL;
    return chotaHead;
}

bool isPalindrome(Node* head) {

    // METHOD 2 : MAKING A REVERSE LIST AND COMPARING NODES
    Node *reversedHead = rev(head);
    print(reversedHead) ;
    // cout << reversedHead << endl;
    while(head != NULL) {
        if(head->data != reversedHead->data)
            return false;
        
        // cout << "head is " << head->data << endl;
        // cout << "revhead is " << reversedHead->data << endl;
        head = head->next;
        reversedHead = reversedHead -> next;
        // cout << head->data << endl;
        // cout << reversedHead->data << endl;
    }
    return true;
}

int main()
{
    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    print(head);
    cout << isPalindrome(head);

}