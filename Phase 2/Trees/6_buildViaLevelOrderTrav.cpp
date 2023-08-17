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

// node* buildTree(node* root){

//     cout << "Enter the data" << endl;
//     int data;
//     cin >> data;
//     root = new node(data);

//     if(data == -1)
//         return NULL;
    
//     cout << "Enter data to be inserted at left of " << data << endl;
//     root -> left = buildTree(root -> left);
//     cout << "Enter data to be inserted at right of " << data << endl;
//     root -> right = buildTree(root -> right);

//     return root;
// }

void buildFromLevelOrder(node* &root){

    queue<node*> q;
    cout << "Enter the data for root node" << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }

}

// also known as BREADTH FIRST SEARCH
void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    // level 0 completed so pushing NULL
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
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


int main()
{
    node *root = NULL;

    // building a tree
    // root = buildTree(root);
    
    buildFromLevelOrder(root);
    // printing in level order traversal
    cout << endl << "level order traversal is" << endl;
    levelOrderTraversal(root);
}