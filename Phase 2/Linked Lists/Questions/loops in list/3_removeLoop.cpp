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
            return slow;
        }
    }
    return NULL;

}

// FINDING STARTING NODE USING FLOYD DETECTION ALGO
Node* getStartNode(Node* head) {
    if(head == NULL)
        return NULL;
    
    Node* intersection = floydDetectLoop(head);

    if(intersection == NULL)
        return NULL;

    Node* slow = head;
    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

// starting node of loop se phle ki node hi last node hoti hai...isko agr null pr point kra 
// diya to loop khtm ho jaega i.e start node se phle ki node find krni h
Node* removeLoop(Node* head) {
    if(head == NULL)
        return NULL;
    // starting node of loop find krli
    Node* startOfLoop = getStartNode(head);

    // agr koi loop present hi nhi ho to head return kr denge
    if(startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop;
    // start node se loop shru krenge..jbtk temp->next same node pr na aa jaye 
    // tbtk loop chlayenge i.e last node tk
    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }
    // last node ko loop se htake null pr point kra diya
    temp -> next = NULL;
    return head;
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

    if (floydDetectLoop(head)) 
        cout << "loop is present" << endl;
    else 
        cout << "loop is not present" << endl;
    
    // loop is present

    Node* startnode = getStartNode(head);
    cout << "starting node of loop is " << startnode -> data << endl;

    removeLoop(head);
    print(head);
    // loop removed

    if (floydDetectLoop(head)) 
        cout << "loop is present" << endl;
    else 
        cout << "loop is not present" << endl;

    // loop is not present
    
}