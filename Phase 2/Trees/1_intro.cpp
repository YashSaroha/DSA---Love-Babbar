#include<iostream>
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
    int val;
    cin >> val;
    root = new node(val);

    if(val == -1)
        return NULL;
    
    cout << "Enter data to be inserted at left of " << val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data to be inserted at right of " << val << endl;
    root -> right = buildTree(root -> right);

    return root;

}


int main()
{
    node *root = NULL;

    // building a tree
    root = buildTree(root);
    
}