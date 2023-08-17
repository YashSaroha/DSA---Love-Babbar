// linked list cycle II   in leetcode

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

// FLOYD'S CYCLE DETECTION ALGO

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

// starting node of loop nikalne ke liye phle to floyd detection algo use krenge
// isse ek jgh slow and fast meet kr jaenge...is time pr slow ko firse head pr daal
// denge and slow or fast ko ab ek ek krke aage bdhaenge
// ab jaha slow or fast milenge whi node hogi starting node of loop

Node* getStartNode(Node* head) {
    if(head == NULL)
        return NULL;
    
    // is point pr slow or fast meet krenge
    Node* intersection = floydDetectLoop(head);

    // meet krne ke baad slow ko firse head pr bhej diya and intersection(jispe fast h) usko b ek ek krke aage bdhaya
    Node* slow = head;
    // jbtk slow and fast dobara meet ni krte tbtk loop chlaya
    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }
    // loop se bahar aaye mtlb dono intersect kiye...yhi node start node hai
    return slow;
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

    if(floydDetectLoop(head)) {
        cout << "loop is present" << endl;
    }
    else {
        cout << "loop is not present" << endl;
    }
    // output -> 10 12 15 22

    Node* startnode = getStartNode(head);
    cout << "starting node of loop is " << startnode -> data << endl;

}