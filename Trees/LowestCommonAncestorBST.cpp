#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

Node * LowestCommonAncestor(Node * root , Node * p , Node * q){
    if(root == NULL) return NULL;
    if(root == p || root == q) return root==q?q:p;
    if(p->data < root->data && q->data < root->data) return LowestCommonAncestor(root->left , p ,q);
    else if (p->data > root->data && q->data > root->data) return LowestCommonAncestor(root->right , p ,q);
    else return root;
}

int main(){
    vector<int> vals = {
    50, 30, 70,
    20, 40, 60, 80,
    10, 25, 35, 45,
    55, 65, 75, 90
};
    Node * root  = buildBST(vals);
    Node * x = LowestCommonAncestor(root , root->right->right->right , root->left->left);
    cout<<x->data<<endl;
}