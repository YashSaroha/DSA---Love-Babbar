// sorting a linked list made of 0,1,2 only

#include <iostream>
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
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// METHOD 1 : HR ELEMENT KA COUNT STORE KRALIA AND THEN UTNI BARI WO ELEMENT LIST ME UPDATE KRDIA

// Node* sortList(Node *head){
    
//     Node *temp = head;
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     while(temp != NULL)
//     {
//         if(temp->data == 0)
//             zeroCount++ ;
//         else if (temp->data == 1)
//             oneCount++ ;
//         else
//             twoCount++ ;
//         temp = temp -> next;
//     }

//     Node *start = head;
//     while(start != NULL) {
        
//         if(zeroCount != 0) {
//             start -> data = 0;
//             zeroCount-- ;
//         }
//         else if( oneCount != 0) {
//             start -> data = 1;
//             oneCount-- ;
//         }
//         else if( twoCount != 0) {
//             start -> data = 2;
//             twoCount-- ;
//         }

//         start = start -> next;
//     }
      
//     return head;
// }



// MEHTOD 2 : DATA IS NOT CHANGED AND ONLY LINKS ARE UPDATED

Node* sortList(Node *head){
    // creating dummy nodes for each sublist of 0s, 1s, 2s
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    
    Node *curr = head;
    
    // created separate list for 0s, 1s, 2s
    while(curr != NULL) {
        int value = curr -> data ;

        if(value == 0) {
            insertAtTail(zeroTail , curr->data);
        }
        else if(value == 1) {
            insertAtTail(oneTail , curr->data);
        }
        else if(value == 2) {
            insertAtTail(twoTail , curr->data);
        }
        curr = curr -> next;
    }

    // merge 3 sublists
    
    // 1s sublist not empty, 0s pointed to 1s and 1s pointed to 2s
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }
    
    // 1s sublist is empty, 0s list pointed directly to 2s list
    else{
        zeroTail -> next = twoHead -> next;
    }
    
    // 2s list pointed to null
    twoTail -> next = NULL;
    
    // head is 0s dummy node ki agli node
    head = zeroHead -> next;
    
    // deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{
    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    print(head);
    
    Node *newHead = sortList(head);
    cout << "sorted list is " ;
    print(newHead);
}
