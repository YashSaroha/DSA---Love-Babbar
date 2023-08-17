// linked list cycle I   in leetcode

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

// METHOD 1
// bool detectLoop(Node *head) {
//     if(head == NULL) {
//     return false;
//     }
//     Node *temp = head;
//     map<Node *, bool> vis;

//     while (temp != NULL) {
//         if (vis[temp] == true){   
//             // agr koi already visited node mil gyi it means it is a loop
//             cout << "loop is present at element " << temp -> data << endl;
//             return true;
//         }
//         // else wo node visited nhi thi to visited mark krdia and next node pr chle gye
//         vis[temp] = true;
//         temp = temp->next;
//     }
//     // if we get null it means singly list h without any loop
//     return false;
// }

// METHOD 2 : FLOYD'S CYCLE DETECTION ALGO

Node* floydDetectLoop(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast){
            cout << "loop present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;

}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 22);
    print(head);
    // making a loop, 22 ko 12 pr point kr denge (22 is tail and 12 is head->next)
    tail -> next = head -> next;

    // if we print(head), it will stuck to print an endless loop because of loop in the list
    // if(detectLoop(head)) {
    //     cout << "loop is present" << endl;
    // }
    // else {
    //     cout << "loop is not present" << endl;
    // }

    if(floydDetectLoop(head)) {
        cout << "loop is present" << endl;
    }
    else {
        cout << "loop is not present" << endl;
    }
    // output -> 10 12 15 22
}