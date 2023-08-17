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

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    // level 0 completed so pushing NULL
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        // pushing separator if level is completed
        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }

    }

}

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

int main()
{
    Node* root = NULL;

    cout << "Enter the data to create binary search tree" << endl;
    takeInput(root);

    // printing level order BST
    cout << "level order traversal of BST is" << endl;
    levelOrderTraversal(root);

    // printing inorder of BST
    cout << endl << "inorder traversal of BST is" << endl;
    inorder(root);
    // 10 2 21 8 9 12 -1
    // INORDER TRAVERSAL OF A BST IS ALWAYS SORTED
    // INORDER PREDECESSOR (e.g 21) : 2 
    // INORDER SUCCESSOR (e.g 21) : 8


}