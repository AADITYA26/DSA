#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
#include <algorithm>
using namespace std;

Node * PreOrderAndInorder(vector<int> &preorder , vector<int> &inorder , int inStart , int inEnd , int &preIndex){
    if(inStart > inEnd) return NULL;
    Node * root = new Node(preorder[preIndex++]);
    int pos = find(inorder.begin(),inorder.end(),root->data) - inorder.begin();
    root->left = PreOrderAndInorder(preorder , inorder , inStart , pos-1 , preIndex);
    root->right = PreOrderAndInorder(preorder , inorder , pos+1 , inEnd , preIndex);
    return root;
}


Node *PostOrderAndInorder(vector<int> &postorder , vector<int> &inorder , int inStart , int inEnd , int &postIndex){
    if(inStart > inEnd) return NULL;
    Node * root = new Node(postorder[postIndex--]);
    int pos = find(inorder.begin(),inorder.end(),root->data)-inorder.begin();
    root->right = PostOrderAndInorder(postorder , inorder , pos+1 , inEnd , postIndex);
    root->left = PostOrderAndInorder(postorder , inorder , inStart , pos-1 , postIndex);
    return root;
}

