#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrderTraverse(Node* root){
    // base case
    if(root == NULL)
        return;

    cout << root -> data << " " ;
    preOrderTraverse(root -> left);
    preOrderTraverse(root -> right);
}


int findPosition(int inorder[], int element, int n){
    for(int i=0 ; i<n ; i++){
        if(inorder[i] == element){
            // to avoid duplicate elements issue, sath sath jis element ko search krenge use -1 kr denge
            inorder[i] = -1;
            return i;
        }
    }
    return -1;
}

Node* solve(int inorder[], int postorder[], int &index, int inorderStart, int inorderEnd, int size){
    
    // base case
    if(index < 0 || inorderStart > inorderEnd)
        return NULL;

    int element = postorder[index--];
    Node* root = new Node(element);

    // find this element in inorder
    int position = findPosition(inorder, element, size);

    // root ke right me phle call jayegi
    root -> right = solve(inorder, postorder, index, position + 1 , inorderEnd, size);
    root -> left = solve(inorder, postorder, index, inorderStart, position - 1 , size);

    return root;

}

int main()
{
    int inorder[6] = {3,1,4,0,5,2};
    int postorder[6] = {3,4,1,5,2,0};
    int size = 6;

    int postOrderIndex = size-1 ;
    Node* root = solve(inorder, postorder, postOrderIndex, 0, size-1, size);
    cout << "pre order traversal of newly build tree is " << endl;
    preOrderTraverse(root);
    return 0;
}