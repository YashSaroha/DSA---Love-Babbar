#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    // constructor
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout << "Enter data to be inserted at left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data to be inserted at right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void inorder(node* root){

    // base case
    if(root == NULL)
        return;

    // inorder -> L-N-R
    inorder(root -> left);
    cout << root -> data << " " ;
    inorder(root -> right);

}


int main()
{
    node *root = NULL;

    // building a tree
    root = buildTree(root);
    
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // tree formed after this input is
    //        1
    //   3         5
    // 7   11    17  NULL

    // inorder traversal -> 7 3 11 1 17 5
    cout << "inorder traversal is : ";
    inorder(root);
}