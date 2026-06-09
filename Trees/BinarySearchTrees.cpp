#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

Node * insert(Node * root , int val){
    if(root ==  NULL) {
        Node * x = new Node(val); 
        return x;
    }
    if(val<root->data)root ->left = insert(root->left , val);
    if(val>root->data)root->right = insert(root->right ,val);
    return root;
}

Node * inorderSucc(Node * root){
    if(root==NULL||root->right==NULL) return NULL;
    root = root->right;
    while(root->left != NULL){
        root = root->left;
    }
    return root;    
}

bool Search(Node * root , int val){
    if(root==NULL)return false;
    if(root->data == val) return true;
    if(root->data < val)return Search(root->right , val);
    else return Search(root->left , val);
}

Node * Delete(Node * root , int val){
    if(root == NULL) return NULL;
    if(root->data < val)root->right = Delete(root->right , val);
    else if(root->data > val) root->left = Delete(root->left,val);
    else{
        if(root->right==NULL&&root->left==NULL){
            delete root;
            return NULL;
        }
        else if(root->right == NULL || root->left==NULL){
            Node * x = root->right!=NULL?root->right:root->left;
            delete root;
            return x;
        }
        else{
            Node * x = inorderSucc(root);
            root->data = x->data;
            root->right = Delete(root->right,x->data);
        }
    }
    return root;
}

Node * buildBST(const vector<int>& vals){
    Node * root = NULL;
    for(int i = 0; i < vals.size();i++){
        root = insert(root,vals[i]);
    }
    return root;
}