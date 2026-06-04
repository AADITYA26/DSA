#include <bits/stdc++.h>
using namespace std;

/*
 Solve(root){
 Solve(leftSubtree)
 Solve(rightSubtree)
 Calculate the root -> Whatever you have to calculate for the node you are at
}
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right = left = NULL;
    }

};

//Building a binary tree from preorder 

static int idx = -1;
Node* BuildTree(vector<int> preOrder){
    idx++;
    if(idx==preOrder.size()||preOrder[idx] ==-1) return NULL; 
    Node *root = new Node(preOrder[idx]);
    root->left = BuildTree(preOrder);
    root->right = BuildTree(preOrder);
    return root;
}

//Traversals
void preorder (Node * root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder (Node * root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postOrder(Node * root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//Level Order Traversal

void levelOrder(Node * root){//NULL MARKER APPROACH
    queue<Node *> q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }

    while(!q.empty()){

        Node * x = q.front();
        q.pop();

        if (x == NULL){//CHECKING FOR A LEVEL MARKER
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);//PUSHING IT AGAIN AT THE END
            }
            continue;//SKIPPING THE OTHER STEPS BECAUSE X IS NULL
        }


        cout<<x->data<<" ";
        if(x->left)
            q.push(x->left);
        if(x->right)
            q.push(x->right);
    }
}

void levelorder_queuesize(Node * root){
    queue<Node *> q;
    if (root!=NULL) {
        q.push(root);
    }
    while(!q.empty()){
        int levelSize = q.size();//measuring the size of each level by the number of elements
        for(int i = 0 ; i < levelSize ; i++){
            auto x = q.front();
            q.pop();
            cout<<x->data<<" ";
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
        cout<<endl;//at the end of the level move onto the next
    }
}


void printTree(Node * root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

// int main(){
//     vector<int> preOrder = {1,2,-1,-1,3,-1,-1};  //NULL pointers are necessary if onyl using preorder to construct 
//     Node * root = BuildTree(preOrder);
//     levelOrder(root);
// }
//The main is commented out because this file is getting imported 

