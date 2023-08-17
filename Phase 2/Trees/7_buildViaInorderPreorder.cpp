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

void postOrderTraverse(Node* root){
    // base case
    if(root == NULL)
        return;

    postOrderTraverse(root -> left);
    postOrderTraverse(root -> right);
    cout << root -> data << " " ;
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

Node* solve(int inorder[], int preorder[], int &index, int inorderStart, int inorderEnd, int size){
    
    // base case
    if(index >= size || inorderStart > inorderEnd)
        return NULL;

    int element = preorder[index++];
    Node* root = new Node(element);

    // find this element in inorder
    int position = findPosition(inorder, element, size);

    // root ke left me phle call jayegi
    root -> left = solve(inorder, preorder, index, inorderStart, position - 1 , size);
    root -> right = solve(inorder, preorder, index, position + 1 , inorderEnd, size);

    return root;

}

int main()
{
    int inorder[6] = {3,1,4,0,5,2};
    int preorder[6] = {0,1,3,4,2,5};
    int size = 6;

    int preOrderIndex = 0;
    Node* root = solve(inorder, preorder, preOrderIndex, 0, size-1, size);
    cout << "post order traversal of newly build tree is " << endl;
    postOrderTraverse(root);
    return 0;
}