#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;


void inorder_traversal(Node * root , vector<int>& ans){
    if(root == NULL) return;
    inorder_traversal(root->left , ans);
    ans.push_back(root->data);
    inorder_traversal(root->right,ans);
    return ;
}

Node * Sorted_BST(vector<int>& vals , int start , int end){
    if(start>end) return NULL;
    int mid  = start + (end-start)/2;
    Node * root  = new Node(vals[mid]);
    root->left = Sorted_BST(vals ,start,mid-1 );
    root->right = Sorted_BST(vals , mid+1 , end);
    return root;
}

Node* merge2BST(Node * root1 , Node * root2){
    if(root1==NULL || root2==NULL)return root1==NULL ? root2:root1;
    vector<int> io1 , io2;
    inorder_traversal(root1 , io1);
    inorder_traversal(root2 , io2);
    vector<int> temp ;
    int i = 0, j = 0;
    while(i <io1.size() && j<io2.size() ){
        if(io1[i]<io2[j])temp.push_back(io1[i++]);
        else temp.push_back(io2[j++]);
    }
    while(i<io1.size()) temp.push_back(io1[i++]);
    while(j<io2.size()) temp.push_back(io2[j++]);
    Node * root = Sorted_BST(temp , 0 , temp.size()-1);
    return root;
}