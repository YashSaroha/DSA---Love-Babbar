#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void inorder(Node* root){

    // base case
    if(root == NULL)
        return;

    // inorder -> L-N-R
    inorder(root -> left);
    cout << root -> data << " " ;
    inorder(root -> right);
}

Node* insertIntoBST(Node* root , int d){

    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d < root->data)
        root -> left = insertIntoBST(root -> left , d);
    else
        root -> right = insertIntoBST(root -> right , d);

    return root;
}

// taking input from user for binary search tree
void takeInput (Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root , data);
        cin >> data;
    }
}

int getMax(Node* root){
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp -> data;
}

int getMin(Node* root){
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp -> data;
}

int main()
{
    Node* root = NULL;

    cout << "Enter the data to create binary search tree" << endl;
    takeInput(root);

    // printing BST
    inorder(root);

    cout << endl;
    cout << "minimun element in BST is : " << getMax(root) << endl;
    cout << "minimun element in BST is : " << getMin(root) << endl;

}